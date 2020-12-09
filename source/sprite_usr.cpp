#include "../include/sprite_usr.h"

sprite_usr::sprite_usr(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y) {
    score = 0;
    blood = USR_BLOOD;
}

sprite_usr::~sprite_usr() = default;

void sprite_usr::auto_move() {
    this->pos_x += this->mov_x;
    this->pos_y += this->mov_y;
    if (pos_x + width > WINDOW_WIDTH) {
        pos_x = WINDOW_WIDTH - width;
    }
    if (pos_x < 0) {
        pos_x = 0;
    }
    if (pos_y + height > WINDOW_HEIGHT) {
        pos_y = WINDOW_HEIGHT - height;
    }
    if (pos_y < 0) {
        pos_y = 0;
    }
}

int sprite_usr::get_score() const {
    return score;
}

void sprite_usr::add_score(int add) {
    score += add;
}

int sprite_usr::get_blood() const {
    return blood;
}

void sprite_usr::add_blood(int add) {
    this->blood += add;
}

void sprite_usr::change_mov(int mov_x, int mov_y) {
    this->mov_x = mov_x;
    this->mov_y = mov_y;
}
