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

void sprite_base::drawSprite(int pic_width, int pic_height) {
    if(pic_width < 0 || pic_height < 0) {
        putImageScale(img, pos_x, pos_y, width, height);
    } else {
        putImageScale(img, pos_x, pos_y, pic_width, pic_height);
    }
}

int sprite_base::get_pos_x() const {
    return pos_x;
}

int sprite_base::get_pos_y() const{
    return pos_y;
}

bool sprite_base::is_inBox() {
    if(pos_x + width <= 0 || pos_x >= WINDOW_WIDTH || \
            pos_y + height <= 0 || pos_y >= WINDOW_HEIGHT)
        return false;
    else
        return true;
}
