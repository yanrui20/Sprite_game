#include "../include/sprite_low.h"

sprite_low::sprite_low(int p_x, int p_y, ACL_Image *p_img, \
                        int width, int height, int mov_x, int mov_y)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y)
{
    score = LOW_SCORE;
}

sprite_low::~sprite_low() = default;

void sprite_low::auto_move() {
    pos_x += mov_x;
    pos_y += mov_y;
}

int sprite_low::get_score() {
    return score;
}
