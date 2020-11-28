#include <iostream>
#include "global.h"

int Setup() {
    initWindow("Sprite Game", DEFAULT, DEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT);
    loadImage("../picture/tom.bmp", &usr_img);
    loadImage("../picture/jerry.bmp", &low_img);
    beginPaint();
    clearDevice();
    putImage(&usr_img, 50, 50);
    endPaint();
    return 0;
}
