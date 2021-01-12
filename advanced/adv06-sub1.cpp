#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

int main(){
    show(1200, 720);
    setColor(0, 125, 75);
    fillRectangle(0, 0, 1200, 700);
    waitForKey();
}