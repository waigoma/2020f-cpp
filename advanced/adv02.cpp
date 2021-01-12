#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

int main(){
    int x = 150, y = 100;

    show(600, 600);

    setColor(0, 0, 0);
    
    // club
    fillTriangle(x, y, x - 50, y + 125, x + 50, y + 125);

    fillCircle(x - 50, y + 25, 50);
    fillCircle(x, y - 35, 50);
    fillCircle(x + 50, y + 25, 50);

    // spade
    x = 400;
    y = 100;
    fillTriangle(x, y, x - 40, y + 125, x + 40, y + 125);
    fillTriangle(x, y - 50, x - 70, y + 20, x + 70, y + 20);

    fillCircle(x - 30, y + 50, 50);
    fillCircle(x + 30, y + 50, 50);

    // heart
    setColor(255, 0, 0);

    x = 150;
    y = 400;
    fillTriangle(x, y + 100, x - 80, y, x + 80, y);

    fillCircle(x - 37, y - 25, 50);
    fillCircle(x + 38, y - 25, 50);

    // diamond
    x = 400;
    y = 400;
    fillTriangle(x, y + 120, x - 60, y, x + 60, y);
    fillTriangle(x, y - 120, x - 60, y, x + 60, y);

    waitForKey();
}