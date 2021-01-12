#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

const int CENTER_X = 250;
const int CENTER_Y = 450;

void drawGraph(){
    drawLine(0, CENTER_Y, 500, CENTER_Y);
    drawLine(500, CENTER_Y, 495, CENTER_Y - 5);
    drawLine(500, CENTER_Y, 495, CENTER_Y + 5);
    drawLine(CENTER_X, 0, CENTER_X, 500);
    drawLine(CENTER_X, 0, CENTER_X - 5, 5);
    drawLine(CENTER_X, 0, CENTER_X + 5, 5);
}

int main(){
    int lastX = -10;
    int lastY = lastX * lastX;
    show(525, 525);
    drawGraph();
    for(int x = -9; x <= 10; x++){
        int y = x * x;
        drawLine(lastX * 20 + CENTER_X, -lastY * 4 + CENTER_Y, x * 20 + CENTER_X, -y * 4 + CENTER_Y);
        lastX = x;
        lastY = y;
    }
    waitForKey();
}