//
// Created by asus on 20/11/28.
//

#include "sprite_usr.h"

sprite_usr::sprite_usr(int p_x, int p_y, ACL_Image *p_img, int width, int height, int speed)
    : sprite_base(p_x, p_y, p_img, width, height, 0, 0) {
    score = 0;
}

sprite_usr::~sprite_usr() = default;

void sprite_usr::move() {

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

int sprite_usr::get_score() const {
    return score;
}
