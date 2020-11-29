#include "sprite_usr.h"

sprite_usr::sprite_usr(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y)
    : sprite_base(p_x, p_y, p_img, width, height, mov_x, mov_y) {
    score = 0;
    blood = USR_BLOOD;
}

sprite_usr::~sprite_usr() = default;

void sprite_usr::auto_move() {
    
}

void sprite_usr::move(int key) {
    switch(key) {
        case VK_UP:
            if(pos_y - mov_y > 0) pos_y -= mov_y;
            else pos_y = 0;
            break;
        case VK_DOWN:
            if(pos_y + mov_y < WINDOW_HEIGHT - height) pos_y += mov_y;
            else pos_y = WINDOW_HEIGHT - height;
            break;
        case VK_LEFT:
            if(pos_x - mov_x > 0) pos_x -= mov_x;
            else pos_x = 0;
            break;
        case VK_RIGHT:
            if(pos_x + mov_x < WINDOW_WIDTH - width) pos_x += mov_x;
            else pos_x = WINDOW_WIDTH - width;
            break;
        default:
            break;
    }
}

int sprite_usr::get_score() {
    return score;
}

void sprite_usr::add_score(int add) {
    score += add;
}

int sprite_usr::get_blood() const {
    return blood;
}

void sprite_usr::add_blood(int a) {
    this->blood += a;
}
