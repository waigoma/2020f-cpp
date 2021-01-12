#include "canvas/canvas.h"
#include <string>
#include <iostream>

using namespace canvas;
using namespace std;

int main(){
    show(500, 500);

    setColor(0, 0, 0);
    
    fillTriangle(200, 175, 150, 300, 250, 300);

    fillCircle(150, 200, 50);
    fillCircle(200, 140, 50);
    fillCircle(250, 200, 50);

    waitForKey();
}