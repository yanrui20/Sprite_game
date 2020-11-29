#include <iostream>
#include "global.h"
#include <ctime>
// #include <zconf.h>
#include "sprite_low.h"
#include "sprite_usr.h"
#include "sprite_bomb.h"

void timerEvent(int id);
void keyboardEvent(int key, int event);
void eat();
void print();
void create_usr();
void create_low(sprite_low ** low);
void create_bomb(sprite_bomb ** bomb);

ACL_Image usr_img, low_img, bomb_img, game_over_img;
const int MAX_LOW = 20;
sprite_low * spriteLow[MAX_LOW] = {nullptr};
sprite_usr * spriteUsr = nullptr;
sprite_bomb * spriteBomb[MAX_BOMB] = {nullptr};
bool game_over = false;
int level = 1;

int Setup() {
    initWindow("Sprite Game", 350, 100, WINDOW_WIDTH, WINDOW_HEIGHT);
    loadImage("../picture/tom.bmp", &usr_img);
    loadImage("../picture/jerry.bmp", &low_img);
    loadImage("../picture/bomb.jpg", &bomb_img);
    loadImage("../picture/GAME_OVER.jpg", &game_over_img);
    srand(time(nullptr));
    create_usr();
    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyboardEvent);
    putImage(&usr_img, 50, 50);
    startTimer(0, 20);
    return 0;
}

void timerEvent(int id){
    if (game_over) return;
    level = spriteUsr->get_score() / 50 + 1;
    eat();
    for(auto & low : spriteLow) {
        if(low) low->auto_move();
        else create_low(&low);
        if (!(low->is_inBox())) {
            delete low;
            low = nullptr;
        }
    }
    for(auto & bomb : spriteBomb) {
        if(bomb) bomb->auto_move();
        else create_bomb(&bomb);
        if (!(bomb->is_inBox())) {
            delete bomb;
            bomb = nullptr;
        }
    }
    print();
}

void keyboardEvent(int key, int event) {
    if(event != KEY_DOWN) return;
    spriteUsr->move(key);
}

void eat() {
    for (auto & low : spriteLow) {
        if (low && low->touch(spriteUsr)) {
            spriteUsr->add_score(low->get_score());
            delete low;
            low = nullptr;
        }
    }
    for (auto & bomb : spriteBomb) {
        if (bomb && bomb->touch(spriteUsr)) {
            spriteUsr->add_blood(BOMB_BLOOD);
            delete bomb;
            bomb = nullptr;
        }
    }
}

void print() {
    beginPaint();
    clearDevice();
    // print usr
    spriteUsr->drawSprite();
    // print low
    for (auto & low : spriteLow) {
        if (low)
            low->drawSprite();
    }
    // print bomb
    for (auto & bomb : spriteBomb) {
        if (bomb)
            bomb->drawSprite();
    }
    // if game over
    if(spriteUsr->get_blood() <= 0) {
        game_over = true;
        putImageScale(&game_over_img, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    // print score, blood, level
    char score_txt[20], blood_txt[20], level_txt[20];
    sprintf_s(score_txt, "Score: %d", spriteUsr->get_score());
    sprintf_s(blood_txt, "Blood: %d", spriteUsr->get_blood());
    sprintf_s(level_txt, "Level: %d", level);
    setTextSize(25);
    setTextColor(BLUE);
    paintText(0, 0, score_txt);
    setTextColor(RED);
    paintText(500, 0, blood_txt);
    setTextColor(GREEN);
    paintText(1050, 0, level_txt);
    endPaint();
}

void create_usr() {
    int x = WINDOW_WIDTH / 2;
    int y = WINDOW_HEIGHT / 2;
    spriteUsr = new sprite_usr(x, y, &usr_img, PIC_SIZE, PIC_SIZE, USR_SPEED, USR_SPEED);
}

void create_low(sprite_low ** low) {
    int x = rand() % (WINDOW_WIDTH - PIC_SIZE);
    int y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
    int mov_x = 0;
    int mov_y = 0;
    while (mov_x == 0 && mov_y == 0) {
        mov_x = (rand() % 3 - 1) * LOW_SPEED;
        mov_y = (rand() % 3 - 1) * LOW_SPEED;
    }
    *low = new sprite_low(x, y, &low_img, PIC_SIZE, PIC_SIZE, mov_x, mov_y);
}

void create_bomb(sprite_bomb ** bomb) {
    int x, y;
    switch (rand() % 4) {
        case 0: // up
            x = rand() % (WINDOW_WIDTH - PIC_SIZE);
            y = 0;
            break;
        case 1: // down
            x = rand() % (WINDOW_WIDTH - PIC_SIZE);
            y = WINDOW_HEIGHT - PIC_SIZE;
            break;
        case 2: // left
            x = 0;
            y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
            break;
        case 3: // right
            x = WINDOW_WIDTH - PIC_SIZE;
            y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
            break;
        default:break;
    }
    int mov_x = 0;
    int mov_y = 0;
    while (mov_x == 0 && mov_y == 0) {
        mov_x = (rand() % 3 - 1) * BOMB_SPEED_EVERY_LEVEL;
        mov_y = (rand() % 3 - 1) * BOMB_SPEED_EVERY_LEVEL;
    }
    mov_x *= level;
    mov_y *= level;
    *bomb = new sprite_bomb(x, y, &bomb_img, PIC_SIZE, PIC_SIZE, mov_x, mov_y);
}