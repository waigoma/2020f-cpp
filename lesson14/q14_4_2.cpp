#include "canvas/canvas.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace canvas;
using namespace std;

const int CENTER_X = 250;
const int CENTER_Y = 250;
const int MULTIPLE_X = 30;
const int MULTIPLE_Y = 200;

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

double quadrature(double start, double end, int num) {
    double sum = 0;
    double pitch = (end - start) / num;

    for(int i = 0; i < num; i++) {
        double x = pitch * i + start;
        double y = cos(x);
        sum += y * pitch;
    }

    return sum;
}

int main(){
    double lastX = -7;
    double lastY = quadrature(0, lastX, 10000);
    show(525, 525);
    drawGraph(4, 5);
    for(double x = -7; x <= 7; x+=0.1){
        double y = quadrature(0, x, 10000);
        drawLine(lastX * MULTIPLE_X + CENTER_X, -lastY * MULTIPLE_Y + CENTER_Y, x * MULTIPLE_X + CENTER_X, -y * MULTIPLE_Y + CENTER_Y);
        lastX = x;
        lastY = y;
    }
    waitForKey();
}