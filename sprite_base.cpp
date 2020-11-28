#include "sprite_base.h"

sprite_base::sprite_base(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y) {
    img = p_img;
    pos_x = p_x;
    pos_y = p_y;
    this->width = width;
    this->height = height;
    this->mov_x = mov_x;
    this->mov_y = mov_y;
}

sprite_base::~sprite_base() = default;

void sprite_base::drawSprite(int pic_width = -1, int pic_height = -1) {
    if(pic_width < 0 || pic_height < 0) {
        putImage(img, pos_x, pos_y);
    } else {
        putImageScale(img, pos_x, pos_y, pic_width, pic_height);
    }
}
