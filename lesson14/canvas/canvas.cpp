/*
 * canvas.cpp
 * cygwin 用の win32api を利用した簡単グラフィックライブラリ
 *
 *  Created on: 2015/07/17
 *      Author: Satoru Fujita
 */

#include "canvas.h"
#include <iostream>
#include <string>
#include <pthread.h>
#include <Windowsx.h>

/*
 * main thread と描画 threadの間でメッセージ交換する ID
 */
#define US_CLEAR 0x1000
#define US_INVALIDATE 0x1001
#define US_COLOR 0x1002
#define US_TEXT_COLOR 0x1003
#define US_TEXT_SIZE 0x1004
#define US_BORDER_WIDTH 0x1005
#define US_DISABLE_REPAINT 0x1006
#define US_ENABLE_REPAINT 0x1007
#define US_SET_REPAINT 0x1008
#define US_STRING_CENTER 0x1100
#define US_STRING_LEFT 0x1101
#define US_STRING_RIGHT 0x1102
#define US_DRAW_LINE 0x1200
#define US_DRAW_RECTANGLE 0x1201
#define US_DRAW_OVAL 0x1202
#define US_DRAW_POLYGON 0x1203
#define US_FILL_LINE 0x1300
#define US_FILL_RECTANGLE 0x1301
#define US_FILL_OVAL 0x1302
#define US_FILL_POLYGON 0x1303

namespace canvas {

/*
 * 文字列表示関数のデータをスレッド間で通信するためのデータクラス
 */
class StringParam {
public:
	int x;
	int y;
	std::string str;
};

//void *canvasLoop(void *arg);
DWORD WINAPI canvasLoop(LPVOID arg);

// UTF8ToShiftJis は現在、未使用
char *UTF8ToShiftJis(const char *bufUTF8);

/*
 * 描画スレッド側の描画実施関数群
 */
void s_clear(WPARAM arg);
void s_setColor(WPARAM arg);
void s_setTextColor(WPARAM arg);
void s_setTextSize(WPARAM arg);
void s_setBorderWidth(WPARAM arg);
void s_disableAutoRepaint();
void s_enableAutoRepaint();
void s_setAutoRepaint(WPARAM arg);
void s_forceRepaint();
void s_drawStringCenter(WPARAM arg);
void s_drawStringLeft(WPARAM arg);
void s_drawStringRight(WPARAM arg);
void s_drawLine(WPARAM arg);
void s_drawRectangle(WPARAM arg);
void s_drawOval(WPARAM arg);
void s_drawPolygon(WPARAM arg);
void s_fillRectangle(WPARAM arg);
void s_fillOval(WPARAM arg);
void s_fillPolygon(WPARAM arg);

/*
 * canvas.cpp 内に閉じた共通変数群
 */
static HWND hWnd;
// バックグラウンドの描画コンテンツ
static HDC hmemDC;
static int width;
static int height;
static HBITMAP hBit;
static HPEN hPen;
static HPEN hOldPen;
static HBRUSH hBrush;
static HBRUSH hOldBrush;
static COLORREF color = RGB(0, 0, 0);
static int borderWidth = 1;
static bool repaintFlag = true;
static char bufShiftJis[MAX_PATH];
static wchar_t bufUnicode[MAX_PATH];
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t key_condition = PTHREAD_COND_INITIALIZER;
static pthread_cond_t mouse_condition = PTHREAD_COND_INITIALIZER;
static bool prepared = false;
// static pthread_t thread;

static int inputKey;
static int xPos;
static int yPos;
static HANDLE hThread;
static DWORD dwThreadId;

void getDefaultFont();

/*
 * Win32APIのコールバック関数
 */
LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wp, LPARAM lp )
{
	switch (msg)
	{
	// ウィンドウ生成時の初期化
	case WM_CREATE:
	{
		HDC hDC = GetDC(hWnd);
		// バックグラウンドの描画オブジェクトの生成
		hmemDC = CreateCompatibleDC(hDC);
		// バックグラウンドの bitmap 生成
		hBit = CreateCompatibleBitmap(hDC, width, height);
		SelectObject(hmemDC, hBit);
		SelectObject(hmemDC, GetStockObject(WHITE_BRUSH));
		PatBlt(hmemDC, 0, 0, width, height, PATCOPY);
		ReleaseDC(hWnd, hDC);

		getDefaultFont();
		prepared = true;
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;

	case WM_KEYDOWN:
	{
		if( wp == VK_ESCAPE )
		{
			// Esc が押されたら終了
			PostQuitMessage(0);
			return 0;
		}
	}
	break;

	// キー入力の判定
	case WM_CHAR:
	{
		pthread_mutex_lock(&mutex);

		// キーを inputKey に設定
		inputKey = (wchar_t)wp;

		// キー入力待ちのメインスレッドを起こす
		pthread_cond_broadcast(&key_condition);
		pthread_mutex_unlock(&mutex);
	}
	break;

	// マウスのクリック
	// 便宜的にボタンを離した時に、クリックと判定する。
	case WM_LBUTTONUP:
	{
		pthread_mutex_lock(&mutex);

		xPos = GET_X_LPARAM(lp);
		yPos = GET_Y_LPARAM(lp);
		pthread_cond_broadcast(&mouse_condition);
		pthread_mutex_unlock(&mutex);
	}
	break;

	// 再描画
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		// pthread_mutex_lock(&mutex);
		HDC hDC = BeginPaint(hWnd, &ps);

		// hmemDC の描画情報をコピーする
		BitBlt(hDC, 0, 0, width, height, hmemDC, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		// pthread_mutex_unlock(&mutex);
	}
	break;

	default:
		break;
	}

	// デフォルトの動作
	return DefWindowProc( hWnd, msg, wp, lp );
}

/*
 * ウィンドウ作成のための内部関数
 */
HWND createWindow(int w, int h)
{
	width = w;
	height = h;
	const char* wc_name = "canvas";

	// UNICODE にするための関数
	MultiByteToWideChar(CP_UTF8, 0, wc_name, strlen(wc_name)+1, bufUnicode, MAX_PATH);

	// ウィンドウクラスの設定
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, &canvas::WndProc, 0L, 0L,
			GetModuleHandle(NULL), NULL,
			LoadCursor( NULL, IDC_ARROW ), (HBRUSH)(COLOR_WINDOW + 1),
			NULL, bufUnicode, NULL };

	if( !RegisterClassEx( &wc ) )
	{
		return NULL;
	}

	// ウィンドウの作成
	if(width == 0) {
		width = CW_USEDEFAULT;
		height = CW_USEDEFAULT;
	}

	// 本来、CreateWindowEx で良いが、強制的に、UNICODE ライブラリである
	// CreateWindowExW を呼び出す。
	return CreateWindowExW( WS_EX_LEFT, bufUnicode, bufUnicode, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			NULL, NULL, wc.hInstance, NULL );
}

/*
 * ウィンドウ生成用の基本操作関数
 */
DWORD WINAPI windowMain(LPVOID arg) {
	int *data = (int *)arg;
	int width = data[0];
	int height = data[1];
	delete data;
	// ウィンドウ作成
	hWnd = createWindow(width, height);

	if( !hWnd )
	{
		return (DWORD)0;
	}

	// ウィンドウ表示
	ShowWindow( hWnd, SW_SHOWDEFAULT );
	UpdateWindow( hWnd );

	canvasLoop(NULL);

	return (DWORD)0;
}

/*
 * 利用者向け関数
 */

/*
 * 画面表示用関数
 *  width: 幅
 *  height: 高さ
 */
int show(int width, int height) {
	// width と height を整数配列で、引き渡す
	int *data = new int[2];
	data[0] = width;
	data[1] = height;
	// スレッド起動
	hThread = CreateThread(
		NULL, // セキュリティ属性
		0, // スタックサイズ
		windowMain, // スレッドで呼び出すmain関数
		data, // main関数に渡す引数
		0, //作成オプション(0またはCREATE_SUSPENDED)
		&dwThreadId); //スレッドID

	// pthread は、とりあえず、使用しないことにする。
	// pthread_create(&thread, NULL, &canvasLoop, NULL );

	while(1) {
		if(!prepared) {
			Sleep(10);
		} else {
			break;
		}
	}

	return 0;
}

/*
 * 画面表示用関数
 */
int show() {
	return show(500, 500);
}

/*
 * メッセージ処理ループ
 */
DWORD WINAPI canvasLoop(LPVOID arg) {
	// メッセージループ
	MSG msg;
	do
	{
		if( GetMessage( &msg, NULL, 0, 0 ) )
		{
			// 本ライブラリで定義したメッセージIDを処理する
			if(msg.message >= 0x1000 && msg.message < 0x4000) {
				WPARAM arg = msg.wParam;
				switch(msg.message) {
				case US_CLEAR:
					s_clear(arg);
					break;
				case US_INVALIDATE:
					s_forceRepaint();
					break;
				case US_COLOR:
					s_setColor(arg);
					break;
				case US_TEXT_COLOR:
					s_setTextColor(arg);
					break;
				case US_TEXT_SIZE:
					s_setTextSize(arg);
					break;
				case US_BORDER_WIDTH:
					s_setBorderWidth(arg);
					break;
				case US_DISABLE_REPAINT:
					s_disableAutoRepaint();
					break;
				case US_ENABLE_REPAINT:
					s_enableAutoRepaint();
					break;
				case US_SET_REPAINT:
					s_setAutoRepaint(arg);
					break;
				case US_STRING_CENTER:
					s_drawStringCenter(arg);
					break;
				case US_STRING_LEFT:
					s_drawStringLeft(arg);
					break;
				case US_STRING_RIGHT:
					s_drawStringRight(arg);
					break;
				case US_DRAW_LINE:
					s_drawLine(arg);
					break;
				case US_DRAW_RECTANGLE:
					s_drawRectangle(arg);
					break;
				case US_DRAW_OVAL:
					s_drawOval(arg);
					break;
				case US_DRAW_POLYGON:
					s_drawPolygon(arg);
					break;
				case US_FILL_RECTANGLE:
					s_fillRectangle(arg);
					break;
				case US_FILL_OVAL:
					s_fillOval(arg);
					break;
				case US_FILL_POLYGON:
					s_fillPolygon(arg);
					break;
				default:
					break;
				}
			} else {
				// std::cout << "GetMessage\n";
				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}
		}
		else
		{
			msg.message = WM_QUIT;	// 終了
		}
	}
	while( msg.message != WM_QUIT );
	exit(0);

	return (DWORD)0;
}

/*
 * 画面クリア
 */
void clear() {
	PostThreadMessage(dwThreadId, US_CLEAR, 0, 0);
}

void s_clear(WPARAM arg) {
	hOldBrush = (HBRUSH)SelectObject(hmemDC, GetStockObject(WHITE_BRUSH));
	// pthread_mutex_lock(&mutex);
	PatBlt(hmemDC, 0, 0, width, height, PATCOPY);
	// pthread_mutex_unlock(&mutex);
	SelectObject(hmemDC, hOldBrush);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
}

/*
 * 中央ぞろえの文字列表示
 *  x: x座標
 *  y: y座標
 *  str: 文字列
 */
void drawStringCenter(int x, int y, std::string str) {
	StringParam *data = new StringParam();
	data->x = x;
	data->y = y;
	data->str = str;
	PostThreadMessage(dwThreadId, US_STRING_CENTER, (WPARAM)data, 0);
}

void s_drawStringCenter(WPARAM arg) {
	StringParam *data = (StringParam *)arg;
	int x = data->x;
	int y = data->y;
	std::string str = data->str;
	delete data;

	//pthread_mutex_lock(&mutex);
	const char *text = str.c_str();
	MultiByteToWideChar(CP_UTF8, 0, text, strlen(text) + 1, bufUnicode, MAX_PATH);
	SetTextAlign(hmemDC, (GetTextAlign(hmemDC) & ~ TA_LEFT & ~TA_RIGHT) | TA_CENTER);
	TextOutW(hmemDC, x, y, bufUnicode, lstrlenW(bufUnicode));
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	//pthread_mutex_unlock(&mutex);
}

/*
 * 左揃えの文字列表示
 *  x: x座標
 *  y: y座標
 *  str: 文字列
 */
void drawStringLeft(int x, int y, std::string str) {
	StringParam *data = new StringParam();
	data->x = x;
	data->y = y;
	data->str = str;
	PostThreadMessage(dwThreadId, US_STRING_LEFT, (WPARAM)data, 0);
}

void s_drawStringLeft(WPARAM arg) {
	StringParam *data = (StringParam *)arg;
	int x = data->x;
	int y = data->y;
	std::string str = data->str;
	delete data;

	//pthread_mutex_lock(&mutex);
	const char *text = str.c_str();
	MultiByteToWideChar(CP_UTF8, 0, text, strlen(text) + 1, bufUnicode, MAX_PATH);
	SetTextAlign(hmemDC, (GetTextAlign(hmemDC) & ~ TA_CENTER & ~TA_RIGHT) | TA_LEFT);
	TextOutW(hmemDC, x, y, bufUnicode, lstrlenW(bufUnicode));
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	//pthread_mutex_unlock(&mutex);
}

/*
 * 右揃えの文字列表示
 *  x: x座標
 *  y: y座標
 *  str: 文字列
 */
void drawStringRight(int x, int y, std::string str) {
	StringParam *data = new StringParam();
	data->x = x;
	data->y = y;
	data->str = str;
	PostThreadMessage(dwThreadId, US_STRING_RIGHT, (WPARAM)data, 0);
}

void s_drawStringRight(WPARAM arg) {
	StringParam *data = (StringParam *)arg;
	int x = data->x;
	int y = data->y;
	std::string str = data->str;
	delete data;

	//pthread_mutex_lock(&mutex);
	const char *text = str.c_str();
	MultiByteToWideChar(CP_UTF8, 0, text, strlen(text) + 1, bufUnicode, MAX_PATH);
	SetTextAlign(hmemDC, (GetTextAlign(hmemDC) & ~ TA_CENTER & ~TA_LEFT) | TA_RIGHT);
	TextOutW(hmemDC, x, y, bufUnicode, lstrlenW(bufUnicode));
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	//pthread_mutex_unlock(&mutex);
}

/*
 * 文字列の描画
 *  x: x座標
 *  y: y座標
 *  str: 文字列
 */
void drawString(int x, int y, std::string str) {
	drawStringLeft(x, y, str);
}

/*
 * 点の描画
 *  x: x座標
 *  y: y座標
 */
void drawPoint(int x, int y) {
	fillRectangle(x, y, 2, 2);
}

/*
 * 線の描画
 *  x0, y0: 始点
 *  x1, y1: 終点
 */
void drawLine(int x0, int y0, int x1, int y1) {
	int *data = new int[4];
	data[0] = x0;
	data[1] = y0;
	data[2] = x1;
	data[3] = y1;
	PostThreadMessage(dwThreadId, US_DRAW_LINE, (WPARAM)data, 0);
}

void s_drawLine(WPARAM arg) {
	int *data = (int *)arg;
	int x0 = data[0];
	int y0 = data[1];
	int x1 = data[2];
	int y1 = data[3];
	delete data;

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	MoveToEx(hmemDC, x0, y0, NULL);
	LineTo(hmemDC, x1, y1);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
}

/*
 * 矩形の線画
 *  x: x座標
 *  y: y座標
 *  width: 幅
 *  height: 高さ
 */
void drawRectangle(int x, int y, int width, int height) {
	int *data = new int[4];
	data[0] = x;
	data[1] = y;
	data[2] = width;
	data[3] = height;
	PostThreadMessage(dwThreadId, US_DRAW_RECTANGLE, (WPARAM)data, 0);
}

void s_drawRectangle(WPARAM arg) {
	int *data = (int *)arg;
	int x = data[0];
	int y = data[1];
	int width = data[2];
	int height = data[3];
	delete data;
	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, GetStockObject(NULL_BRUSH));
	Rectangle(hmemDC, x, y, x + width, y + height);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	if(repaintFlag) {
		//pthread_mutex_lock(&mutex);
		InvalidateRect(hWnd, NULL, TRUE);
		//pthread_mutex_unlock(&mutex);
	}
	// pthread_mutex_unlock(&mutex);
}

/*
 * 楕円の線画
 *  x: x座標
 *  y: y座標
 *  width: 幅
 *  height: 高さ
 */
void drawOval(int x, int y, int width, int height) {
	int *data = new int[4];
	data[0] = x;
	data[1] = y;
	data[2] = width;
	data[3] = height;
	PostThreadMessage(dwThreadId, US_DRAW_OVAL, (WPARAM)data, 0);
}

void s_drawOval(WPARAM arg) {
	int *data = (int *)arg;
	int x = data[0];
	int y = data[1];
	int width = data[2];
	int height = data[3];
	delete data;

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, GetStockObject(NULL_BRUSH));
	Ellipse(hmemDC, x, y, x + width, y + height);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
}

/*
 * 円の線画
 *  x: x座標
 *  y: y座標
 *  r: 半径
 */
void drawCircle(int x, int y, int r) {
	drawOval(x - r, y - r, r + r, r + r);
}

/*
 * 三角形の線画
 *  x0, y0: 第一点
 *  x1, y1: 第二点
 *  x2, y2: 第三点
 */
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	int x[3] = {x0, x1, x2};
	int y[3] = {y0, y1, y2};
	drawPolygon(x, y, 3);
}

/*
 * 多角形の線画
 *  xp: x座標の配列
 *  yp: y座標の配列
 *  points: 点の数
 */
void drawPolygon(int *xp, int *yp, int points) {
	POINT *data = new POINT[points + 1];
	for(int i = 0; i < points; i++) {
		data[i + 1].x = xp[i];
		data[i + 1].y = yp[i];
	}
	data[0].x = points;
	PostThreadMessage(dwThreadId, US_DRAW_POLYGON, (WPARAM)data, 0);
}

void s_drawPolygon(WPARAM arg) {
	POINT *p = (POINT *)arg;
	int points = p[0].x;
	p++;

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, GetStockObject(NULL_BRUSH));
	Polygon(hmemDC, p, points);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
	delete (POINT *)arg;
}

/*
 * 矩形の塗りつぶし
 *  x: x座標
 *  y: y座標
 *  width: 幅
 *  height: 高さ
 */
void fillRectangle(int x, int y, int width, int height) {
	int *data = new int[4];
	data[0] = x;
	data[1] = y;
	data[2] = width;
	data[3] = height;
	PostThreadMessage(dwThreadId, US_FILL_RECTANGLE, (WPARAM)data, 0);
}

void s_fillRectangle(WPARAM arg) {
	int *data = (int *)arg;
	int x = data[0];
	int y = data[1];
	int width = data[2];
	int height = data[3];
	delete data;

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hBrush = (HBRUSH)CreateSolidBrush(color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, hBrush);
	Rectangle(hmemDC, x, y, x + width, y + height);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
}

/*
 * 楕円の塗りつぶし
 *  x: x座標
 *  y: y座標
 *  width: 幅
 *  height: 高さ
 */
void fillOval(int x, int y, int width, int height) {
	int *data = new int[4];
	data[0] = x;
	data[1] = y;
	data[2] = width;
	data[3] = height;
	PostThreadMessage(dwThreadId, US_FILL_OVAL, (WPARAM)data, 0);
}

void s_fillOval(WPARAM arg) {
	int *data = (int *)arg;
	int x = data[0];
	int y = data[1];
	int width = data[2];
	int height = data[3];
	delete data;

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hBrush = (HBRUSH)CreateSolidBrush(color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, hBrush);
	Ellipse(hmemDC, x, y, x + width, y + height);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
}

/*
 * 円の塗りつぶし
 *  x: x座標
 *  y: y座標
 *  r: 半径
 */
void fillCircle(int x, int y, int r) {
	fillOval(x - r, y - r, r + r, r + r);
}

/*
 * 三角形の塗りつぶし
 *  x0, y0: 第一点
 *  x1, y1: 第二点
 *  x2, y2: 第三点
 */
void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	int x[3] = {x0, x1, x2};
	int y[3] = {y0, y1, y2};
	fillPolygon(x, y, 3);
}

/*
 * 多角形の塗りつぶし
 *  xp: x座標の配列
 *  yp: y座標の配列
 *  points: 点の数
 */
void fillPolygon(int *xp, int *yp, int points) {
	POINT *data = new POINT[points + 1];
	for(int i = 0; i < points; i++) {
		data[i + 1].x = xp[i];
		data[i + 1].y = yp[i];
	}
	data[0].x = points;
	PostThreadMessage(dwThreadId, US_FILL_POLYGON, (WPARAM)data, 0);
}

void s_fillPolygon(WPARAM arg) {
	POINT *p = (POINT *)arg;
	int points = p[0].x;
	p = &p[1];

	// pthread_mutex_lock(&mutex);
	hPen = (HPEN)CreatePen(PS_SOLID, borderWidth, color);
	hBrush = (HBRUSH)CreateSolidBrush(color);
	hOldPen = (HPEN)SelectObject(hmemDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(hmemDC, hBrush);
	Polygon(hmemDC, p, points);
	SelectObject(hmemDC, hOldBrush);
	SelectObject(hmemDC, hOldPen);
	DeleteObject(hPen);
	DeleteObject(hBrush);
	if(repaintFlag) {
		InvalidateRect(hWnd, NULL, TRUE);
	}
	// pthread_mutex_unlock(&mutex);
	delete (POINT *)arg;
}

/*
 * 図形の色設定
 *  r: 赤
 *  g: 緑
 *  b: 青
 */
void setColor(int r, int g, int b) {
	int *data = new int[3];
	data[0] = r;
	data[1] = g;
	data[2] = b;
	PostThreadMessage(dwThreadId, US_COLOR, (WPARAM)data, 0);
}

void s_setColor(WPARAM arg) {
	int *data = (int *)arg;
	int r = data[0];
	int g = data[1];
	int b = data[2];
	delete data;
	color = RGB(r, g, b);
}

/*
 * 文字列の色設定
 *  r: 赤
 *  g: 緑
 *  b: 青
 */
void setTextColor(int r, int g, int b) {
	int *data = new int[3];
	data[0] = r;
	data[1] = g;
	data[2] = b;
	PostThreadMessage(dwThreadId, US_TEXT_COLOR, (WPARAM)data, 0);
}

void s_setTextColor(WPARAM arg) {
	int *data = (int *)arg;
	int r = data[0];
	int g = data[1];
	int b = data[2];
	delete data;
	// pthread_mutex_lock(&mutex);
	SetTextColor(hmemDC, RGB(r, g, b));
	// pthread_mutex_unlock(&mutex);
}

/*
 * 図形の線幅の設定
 *  width: 線幅
 */
void setBorderWidth(int width) {
	PostThreadMessage(dwThreadId, US_BORDER_WIDTH, (WPARAM)width, 0);
}

void s_setBorderWidth(WPARAM arg) {
	int width = (int)arg;
	borderWidth = width;
}

/*
 * 自動再描画を無効化
 */
void disableAutoRepaint() {
	PostThreadMessage(dwThreadId, US_DISABLE_REPAINT, 0, 0);
}

void s_disableAutoRepaint() {
	repaintFlag = false;
}

/*
 * 自動再描画を有効化
 */
void enableAutoRepaint() {
	PostThreadMessage(dwThreadId, US_ENABLE_REPAINT, 0, 0);
}

void s_enableAutoRepaint() {
	repaintFlag = true;
}

/*
 * 自動再描画の有効/無効を設定する
 *  flag: 再描画の有効/無効を指定
 */
void setAutoRepaint(bool flag) {
	PostThreadMessage(dwThreadId, US_SET_REPAINT, WPARAM(flag), 0);
}

void s_setAutoRepaint(WPARAM arg) {
	repaintFlag = (bool)arg;
}

/*
 * 強制的に再描画する
 */
void forceRepaint() {
	PostThreadMessage(dwThreadId, US_INVALIDATE, 0, 0);
}

void s_forceRepaint() {
	InvalidateRect(hWnd, NULL, TRUE);
}

/*
 * 文字列のフォントサイズを指定
 *  size: フォントサイズ (負のサイズは文字列反転)
 */
void setTextSize(int size) {
	PostThreadMessage(dwThreadId, US_TEXT_SIZE, (WPARAM)size, 0);
}

void s_setTextSize(WPARAM arg) {
	int size = (int)arg;
	int angle = 0;
	HFONT hFontDefGUI = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);

	if(size < 0) {
		size = - size;
		angle = 1800;
	}
	//デフォルトGUIフォントの情報を取り出す
	LOGFONT lf = {0};
	GetObject(hFontDefGUI, sizeof(lf), &lf);
	lf.lfHeight = size;
	lf.lfEscapement = angle;
	HFONT hFontNew = ::CreateFontIndirect(&lf);
	HFONT hOldFont = (HFONT)SelectObject(hmemDC, hFontNew);
	DeleteObject(hOldFont);
}

/*
 * キー入力の待ち関数
 */
void waitForKey() {
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&key_condition, &mutex);
	pthread_mutex_unlock(&mutex);
}

/*
 * マウスボタン入力の待ち関数
 */
void waitForPoint() {
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&mouse_condition, &mutex);
	pthread_mutex_unlock(&mutex);
}

/*
 * 時間待ち関数
 *  time: 待ち時間(ミリ秒)
 */
void waitForCountdown(long time) {
	Sleep(time);
}

/*
 * 入力キーの取得
 */
char getKey() {
	return (char)inputKey;
}

/*
 * マウスのx座標の取得
 */
int getPointedX() {
	return xPos;
}

/*
 * マウスのy座標の取得
 */
int getPointedY() {
	return yPos;
}

/*
 * UTF8 から ShiftJis に変換する関数
 * 現在は未使用
 */
char *UTF8ToShiftJis(const char *bufUTF8)
{
    unsigned int iLenUnicode = MultiByteToWideChar(CP_UTF8, 0, bufUTF8, strlen(bufUTF8)+1, NULL, 0);
    if (iLenUnicode <= sizeof(bufUnicode)/sizeof(bufUnicode[0]))
    {
        MultiByteToWideChar(CP_UTF8, 0, bufUTF8, strlen(bufUTF8)+1, bufUnicode, MAX_PATH);

        unsigned int iLenUtf8 = WideCharToMultiByte(CP_ACP, 0, bufUnicode, iLenUnicode, NULL, 0,
                                                  NULL, NULL);
        if (iLenUtf8 <= sizeof(bufUTF8))
        {
            WideCharToMultiByte(CP_ACP, 0,
                                     bufUnicode, iLenUnicode,
                                     bufShiftJis, sizeof(bufShiftJis),
                                     NULL, NULL);
        } else {
        	bufShiftJis[0] = (char)NULL;
        }
    } else {
    	bufShiftJis[0] = (char)NULL;
    }
    return bufShiftJis;
}

void getDefaultFont() {
	HFONT hFontDefGUI = (HFONT)::GetStockObject(DEFAULT_GUI_FONT);

	//デフォルトGUIフォントの情報を取り出す
	LOGFONT lf = {0};
	GetObject(hFontDefGUI, sizeof(lf), &lf);

	/*
	wchar_t* str = lf.lfFaceName;
	int size = lstrlenW(str);

    WideCharToMultiByte(CP_ACP, 0,
                             str, size,
                             bufShiftJis, sizeof(bufShiftJis),
                             NULL, NULL);

	std::cout << "フォントの名前" << bufShiftJis << std::endl;
	std::cout << "フォントの高さ" << lf.lfHeight << std::endl;
	std::cout << "フォントの幅" << lf.lfWidth << std::endl;
	*/

	//サイズを2倍にする
	HFONT hFontNew = ::CreateFontIndirect(&lf);
	SelectObject(hmemDC, hFontNew);
}

}
