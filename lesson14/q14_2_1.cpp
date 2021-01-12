#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

const int CENTER_X = 250;
const int CENTER_Y = 250;

void drawGraph(int scaleX, int scaleY){
    drawLine(0, CENTER_Y, 500, CENTER_Y);
    drawLine(500, CENTER_Y, 495, CENTER_Y - 5);
    drawLine(500, CENTER_Y, 495, CENTER_Y + 5);
    drawLine(CENTER_X, 0, CENTER_X, 500);
    drawLine(CENTER_X, 0, CENTER_X - 5, 5);
    drawLine(CENTER_X, 0, CENTER_X + 5, 5);
    double spaceX = CENTER_X / (scaleX + 1);
    double spaceY = CENTER_Y / (scaleY + 1);
    for (int x = 1; x <= scaleX; x++){
        drawLine(CENTER_X - spaceX * x, CENTER_Y, CENTER_X - spaceX * x, CENTER_Y - 10);
        drawLine(CENTER_X + spaceX * x, CENTER_Y, CENTER_X + spaceX * x, CENTER_Y - 10);
    }
    for (int y = 1; y <= scaleY; y++){
        drawLine(CENTER_X, CENTER_Y - spaceY * y, CENTER_X + 10, CENTER_Y - spaceY * y);
        drawLine(CENTER_X, CENTER_Y + spaceY * y, CENTER_X + 10, CENTER_Y + spaceY * y);
    }
}

int main(){
    double lastX = -4;
    double lastY = (lastX * lastX * lastX) + (lastX * lastX) - (6 * lastX) + 1;
    show(525, 525);
    drawGraph(4, 5);
    for(double x = -4; x <= 4; x+=0.1){
        double y = (x * x * x) + (x * x) - (6 * x) + 1;
        drawLine(lastX * 50 + CENTER_X, -lastY * 40 + CENTER_Y, x * 50 + CENTER_X, -y * 40 + CENTER_Y);
        lastX = x;
        lastY = y;
    }
    waitForKey();
}