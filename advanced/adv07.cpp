#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

void spade(int, int, double);
void club(int, int, double);
void heart(int, int, double);
void diamond(int, int, double);
void drawSuit(int, int, int, double);
void drawCard(int, int, int, int);
void drawDumCard(int, int);
void drawA(int, int, int);
void draw2(int, int, int);
void draw3(int, int, int);
void draw4(int, int, int);
void draw5(int, int, int);
void draw6(int, int, int);
void draw7(int, int, int);
void draw8(int, int, int);
void draw9(int, int, int);
void draw10(int, int, int);
void drawJ(int, int, int);
void drawQ(int, int, int);
void drawK(int, int, int);

int main(){
    show(1500, 720);
    setColor(0, 125, 75);
    fillRectangle(0, 0, 1500, 700);
    int x = 25;
    int y = 25;
    for(int suit = 0; suit < 4; suit++){
        for(int num = 1; num <= 13; num++){
            drawDumCard(50 + num * 85, 50 + suit * 125);
        }
    }

    while(true){
        waitForPoint();
        int i = (getPointedY() - 50) / 125;
        int j = (getPointedX() - 50) / 85;
        drawCard(i, j, 50 + j * 85, 50 + i * 125);
    }
}

void spade(int x, int y, double s){
    setColor(0, 0, 0);
    fillTriangle(x, y, x - 40 * s, y + 125 * s, x + 40 * s, y + 125 * s);
    fillTriangle(x, y - 50 * s, x - 70 * s, y + 20 * s, x + 70 * s, y + 20 * s);

    fillCircle(x - 30 * s, y + 50 * s, 50 * s);
    fillCircle(x + 30 * s, y + 50 * s, 50 * s);
}

void club(int x, int y, double s){
    setColor(0, 0, 0);
    fillTriangle(x, y, x - 50 * s, y + 125 * s, x + 50 * s, y + 125 * s);

    fillCircle(x - 50 * s, y + 25 * s, 50 * s);
    fillCircle(x, y - 35 * s, 50 * s);
    fillCircle(x + 50 * s, y + 25 * s, 50 * s);
}

void heart(int x, int y, double s){
    setColor(255, 0, 0);
    fillTriangle(x, y + 100 * s, x - 80 * s, y, x + 80 * s, y);

    fillCircle(x - 37 * s, y - 25 * s, 50 * s);
    fillCircle(x + 38 * s, y - 25 * s, 50 * s);
}

void diamond(int x, int y, double s){
    setColor(255, 0, 0);
    fillTriangle(x, y + 120 * s, x - 60 * s, y, x + 60 * s, y);
    fillTriangle(x, y - 120 * s, x - 60 * s, y, x + 60 * s, y);
}

void drawA(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "A");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 60, .15);
    setTextColor(0, 0, 0);
}

void draw2(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "2");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 24, .07);
    drawSuit(suit, x + 40, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw3(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "3");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 40, y + 24, .07);
    drawSuit(suit, x + 40, y + 60, .07);
    drawSuit(suit, x + 40, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw4(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "4");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw5(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "5");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 60, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw6(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "6");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw7(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "7");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 48, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw8(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "8");
    drawSuit(suit, x + 8, y + 26, .07);
    
    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 60, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 48, .07);
    drawSuit(suit, x + 40, y + 72, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 60, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw9(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "9");
    drawSuit(suit, x + 8, y + 26, .07);

    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 48, .07);
    drawSuit(suit, x + 25, y + 72, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 60, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 48, .07);
    drawSuit(suit, x + 55, y + 72, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void draw10(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "10");
    drawSuit(suit, x + 8, y + 26, .07);

    drawSuit(suit, x + 25, y + 24, .07);
    drawSuit(suit, x + 25, y + 48, .07);
    drawSuit(suit, x + 25, y + 72, .07);
    drawSuit(suit, x + 25, y + 96, .07);

    drawSuit(suit, x + 40, y + 36, .07);
    drawSuit(suit, x + 40, y + 84, .07);

    drawSuit(suit, x + 55, y + 24, .07);
    drawSuit(suit, x + 55, y + 48, .07);
    drawSuit(suit, x + 55, y + 72, .07);
    drawSuit(suit, x + 55, y + 96, .07);
    setTextColor(0, 0, 0);
}

void drawJ(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "J");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawQ(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "Q");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawK(int suit, int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);
    if(suit == 1 || suit == 2) setTextColor(255, 0, 0);
    drawString(x + 4, y + 8, "K");
    drawSuit(suit, x + 8, y + 26, .07);

    drawRectangle(x + 20, y + 30, 40, 60);
    setTextColor(0, 0, 0);
}

void drawSuit(int suit, int x, int y, double s){
    switch (suit){
        case 0: // spade
            spade(x, y, s);
            break;
        case 1: // heart
            heart(x, y, s);
            break;
        case 2: // diamond
            diamond(x, y, s);
            break;
        case 3: // club
            club(x, y, s);
            break;
    }
}

void drawDumCard(int x, int y){
    setColor(255, 255, 255);
    fillRectangle(x, y, 80, 120);

    setColor(200, 0, 0);
    drawRectangle(x + 10, y + 10, 60, 100);

    setColor(200, 0, 0);
    fillRectangle(x + 20, y + 20, 40, 80);
    setTextColor(0, 0, 0);
}

void drawCard(int suit, int rank, int x, int y){
    switch (rank){
    case 1:
        drawA(suit, x, y);
        break;
    case 2:
        draw2(suit, x, y);
        break;
    case 3:
        draw3(suit, x, y);
        break;
    case 4:
        draw4(suit, x, y);
        break;
    case 5:
        draw5(suit, x, y);
        break;
    case 6:
        draw6(suit, x, y);
        break;
    case 7:
        draw7(suit, x, y);
        break;
    case 8:
        draw8(suit, x, y);
        break;
    case 9:
        draw9(suit, x, y);
        break;
    case 10:
        draw10(suit, x, y);
        break;
    case 11:
        drawJ(suit, x, y);
        break;
    case 12:
        drawQ(suit, x, y);
        break;
    case 13:
        drawK(suit, x, y);
        break;
    }
}