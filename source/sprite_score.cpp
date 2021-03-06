#include "../include/sprite_score.h"

sprite_score::sprite_score(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y, int score)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y)
{
    this->score = score;
}

sprite_score::~sprite_score() = default;

void sprite_score::auto_move() {
    pos_x += mov_x;
    pos_y += mov_y;
}

int sprite_score::get_score() const {
    return score;
}

