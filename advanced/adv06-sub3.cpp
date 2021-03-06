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
    show(1200, 720);
    setColor(0, 125, 75);
    fillRectangle(0, 0, 1200, 700);
    drawJ(2, 50, 50);
    waitForKey();
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
