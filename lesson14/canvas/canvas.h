/*
 * canvas.h
 *
 *  cygwin 用の win32api を利用した簡単グラフィックライブラリ
 *
 *  Created on: 2015/07/17
 *      Author: Satoru Fujita
 */

#ifndef CWINLIB_CANVAS_H_
#define CWINLIB_CANVAS_H_

#define UNICODE

#include <windows.h>
#include <string>

/*
 * このライブラリで利用する名前空間 canvas を宣言
 */
namespace canvas {

// 画面表示関数。規定値として、500, 500 の画面を生成
int show();

// 画面表示関数。
int show(int width, int height);

// 図形の色指定
void setColor(int r, int g, int b);

// 図形の線幅指定
void setBorderWidth(int width);

// 文字列の色指定
void setTextColor(int r, int g, int b);

// 文字列のフォント指定
void setTextSize(int x);

// 画面のクリア
void clear();

// 文字列表示関数群
void drawString(int x, int y, std::string str);
void drawStringCenter(int x, int y, std::string str);
void drawStringLeft(int x, int y, std::string str);
void drawStringRight(int x, int y, std::string str);

// 図形表示関数群
// draw系 は線画で、fill系 は塗りつぶし
void drawPoint(int x, int y);
void drawLine(int x0, int y0, int x1, int y1);
void drawRectangle(int x, int y, int width, int height);
void drawOval(int x, int y, int width, int height);
void drawCircle(int x, int y, int r);
void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
void drawPolygon(int *xPoints, int *yPoints, int points);
void fillRectangle(int x, int y, int width, int height);
void fillOval(int x, int y, int width, int height);
void fillCircle(int x, int y, int r);
void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2);
void fillPolygon(int *xPoints, int *yPoints, int points);

/*
 * キーボードやマウスクリック用の関数。
 * waitForKey() はキー入力を待ち、その後、getKey() でキーデータ取得
 * waitForPoint() はマウスクリックを待ち、その後、getPointedX/Y で座標取得
 * waitForCountdown は、指定したミリ秒だけ待つ。
 */
void waitForKey();
void waitForPoint();
void waitForCountdown(long msec);
char getKey();
int getPointedX();
int getPointedY();

/*
 * 未実装の関数
 */
/*
void drawImage(int x, int y, String fileName);
void setSize(int w, int h);
*/

/*
 * 自動再描画の制御
 * 通常は、関数呼び出しごとに再描画を要求するので速度が遅い
 * disableAutoRepaint() を呼んだ後、図形関数を呼ぶと、再描画しない。
 * 再描画したいタイミングで、forceRepaint() を呼び出すと良い。
 */
void disableAutoRepaint();
void enableAutoRepaint();
void setAutoRepaint(bool flag);
void forceRepaint();

};

#endif /* CWINLIB_CANVAS_H_ */
