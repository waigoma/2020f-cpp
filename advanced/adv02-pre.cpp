#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

int main(){
    int x = 150, y = 100;

    show(600, 600);

    setColor(0, 0, 0);
    
    // club1
    fillTriangle(x, y, x - 50, y + 125, x + 50, y + 125);

    fillCircle(x - 50, y + 25, 50);
    fillCircle(x, y - 35, 50);
    fillCircle(x + 50, y + 25, 50);

    // club2
    x = 150;
    y = 400;
    fillTriangle(x, y, x - 50, y + 125, x + 50, y + 125);

    fillCircle(x - 50, y + 25, 50);
    fillCircle(x, y - 35, 50);
    fillCircle(x + 50, y + 25, 50);

    // club3
    x = 400;
    y = 100;
    fillTriangle(x, y, x - 50, y + 125, x + 50, y + 125);

    fillCircle(x - 50, y + 25, 50);
    fillCircle(x, y - 35, 50);
    fillCircle(x + 50, y + 25, 50);

    // club4
    x = 400;
    y = 400;
    fillTriangle(x, y, x - 50, y + 125, x + 50, y + 125);

    fillCircle(x - 50, y + 25, 50);
    fillCircle(x, y - 35, 50);
    fillCircle(x + 50, y + 25, 50);

    waitForKey();
}