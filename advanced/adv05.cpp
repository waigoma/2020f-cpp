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

int main(){
    show(600, 600);
    drawSuit(0, 50, 50, .5);
    drawSuit(1, 500, 50, .5);
    drawSuit(2, 50, 500, .5);
    drawSuit(3, 500, 500, .5);
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

