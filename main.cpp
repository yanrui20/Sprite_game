#include <iostream>
#include "acllib.h"

int Setup() {
    initWindow("My Window", DEFAULT, DEFAULT, 640, 480);
    beginPaint();
    setTextSize(100);
    paintText(100, 100, "Hi~");
    endPaint();
    return 0;
}
