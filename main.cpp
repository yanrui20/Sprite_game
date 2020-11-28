#include <iostream>
#include "global.h"
#include <ctime>
#include "sprite_low.h"
#include "sprite_usr.h"

void timerEvent(int id);
void keyboardEvent(int key, int event);
void eat();
bool touch(const sprite_low * low);
void print();
void create_usr();
void create_low(sprite_low ** low);

ACL_Image usr_img, low_img;
const int MAX_LOW = 20;
sprite_low * spriteLow[MAX_LOW] = {nullptr};
sprite_usr * spriteUsr = nullptr;

int Setup() {
    initWindow("Sprite Game", 350, 100, WINDOW_WIDTH, WINDOW_HEIGHT);
    loadImage("../picture/tom.bmp", &usr_img);
    loadImage("../picture/jerry.bmp", &low_img);
    srand(time(nullptr));
    create_usr();
    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyboardEvent);
    putImage(&usr_img, 50, 50);
    startTimer(0, 20);
    return 0;
}

void timerEvent(int id){
    eat();
    for(auto & low : spriteLow) {
        if(low) low->move();
        else create_low(&low);
        if (!(low->is_inBox())) {
            delete low;
            low = nullptr;
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
        if (low && touch(low)) {
            spriteUsr->add_score(low->get_score());
            delete low;
            low = nullptr;
        }
    }
}

bool touch(const sprite_low * low) {
    int xl = low->get_pos_x();
    int yl = low->get_pos_y();
    int xu = spriteUsr->get_pos_x();
    int yu = spriteUsr->get_pos_y();
    if ((xl >= xu && xl <= xu + PIC_SIZE && yl >= yu && yl <= yu + PIC_SIZE) || \
        (xl >= xu && xl <= xu + PIC_SIZE && yl + PIC_SIZE >= yu && yl <= yu) || \
        (xl + PIC_SIZE >= xu && xl <= xu && yl >= yu && yl <= yu + PIC_SIZE) || \
        (xl + PIC_SIZE >= xu && xl <= xu && yl + PIC_SIZE >= yu && yl <= yu) )
        return true; // left_up, left_down, right_up, right_down
    return false;
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
    // print score
    char txt[20];
    sprintf_s(txt, "score: %d", spriteUsr->get_score());
    setTextSize(25);
    setTextColor(BLUE);
    paintText(0, 0, txt);
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