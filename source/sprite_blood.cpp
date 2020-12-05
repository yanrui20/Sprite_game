//
// Created by asus on 20/11/29.
//

#include "../include/sprite_blood.h"

sprite_blood::sprite_blood(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y, int blood)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y) {
    this->blood = blood;
}

sprite_blood::~sprite_blood() = default;

void sprite_blood::auto_move() {
    pos_x += mov_x;
    pos_y += mov_y;
}

int sprite_blood::get_special_value() {
    return this->blood;
}


