#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

int main(){
    const int CX = 250;
    const int CY = 250;
    int lastX = -3;
    int lastY = lastX * lastX;
    show(525, 525);
    for(int x = -2; x <= 3; x++){
        int y = x * x;
        drawLine(lastX * 25 + CX, lastY * 25 + CY, x * 25 + CX, y * 25 + CY);
        lastX = x;
        lastY = y;
    }
    waitForKey();
}