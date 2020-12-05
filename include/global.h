#ifndef SPRITE_GAME_GLOBAL_H
#define SPRITE_GAME_GLOBAL_H
#include "../include/acllib.h"

// window
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
// text
const int TEXT_SIZE = 25;
// picture
const int PIC_SIZE = 50;
// score
    // up
    const int MAX_SPRITE_SCORE_UP = 20;
    const int SCORE_UP_SCORE = 1;
    const int SCORE_UP_SPEED = 2;
    // down
    const int MAX_SPRITE_SCORE_DOWN = 5;
    const int SCORE_DOWN_SCORE = -5;
    const int SCORE_DOWN_SPEED = 10;
// usr
const int USR_START_SPEED = 10;
const int USR_MAX_SPEED = 30;
const int USR_MIN_SPEED = 5;
const int USR_BLOOD = 10;
// blood
const int SPEED_EVERY_LEVEL = 5;
    // bomb
    const int BOMB_BLOOD = -1;
    const int MAX_BOMB = 10;
    // heart
    const int MAX_HEART = 3;
    const int HEART_BLOOD = 1;

#endif //SPRITE_GAME_GLOBAL_H
