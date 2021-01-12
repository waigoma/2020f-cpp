#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

const int CENTER_X = 250;
const int CENTER_Y = 250;

void drawGraph(){
    drawLine(0, CENTER_Y, 500, CENTER_Y);
    drawLine(500, CENTER_Y, 495, CENTER_Y - 5);
    drawLine(500, CENTER_Y, 495, CENTER_Y + 5);
    drawLine(CENTER_X, 0, CENTER_X, 500);
    drawLine(CENTER_X, 0, CENTER_X - 5, 5);
    drawLine(CENTER_X, 0, CENTER_X + 5, 5);
}

int main(){
    int lastX = -3;
    int lastY = lastX * lastX;
    show(525, 525);
    drawGraph();
    for(int x = -2; x <= 3; x++){
        int y = x * x;
        drawLine(lastX * 25 + CENTER_X, -lastY * 25 + CENTER_Y, x * 25 + CENTER_X, -y * 25 + CENTER_Y);
        lastX = x;
        lastY = y;
    }
    waitForKey();
}