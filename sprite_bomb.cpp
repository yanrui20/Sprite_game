//
// Created by asus on 20/11/29.
//

#include "sprite_bomb.h"

sprite_bomb::sprite_bomb(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y) {
}

sprite_bomb::~sprite_bomb() = default;

void sprite_bomb::auto_move() {
    pos_x += mov_x;
    pos_y += mov_y;
}

int sprite_bomb::get_score() {
    return 0;
}


