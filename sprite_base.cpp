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

bool sprite_base::touch(const sprite_base *sprite) const {
    int xu = sprite->get_pos_x();
    int yu = sprite->get_pos_y();
    if ((pos_x >= xu && pos_x <= xu + PIC_SIZE && pos_y >= yu && pos_y <= yu + PIC_SIZE) || \
        (pos_x >= xu && pos_x <= xu + PIC_SIZE && pos_y + PIC_SIZE >= yu && pos_y <= yu) || \
        (pos_x + PIC_SIZE >= xu && pos_x <= xu && pos_y >= yu && pos_y <= yu + PIC_SIZE) || \
        (pos_x + PIC_SIZE >= xu && pos_x <= xu && pos_y + PIC_SIZE >= yu && pos_y <= yu) )
        return true; // left_up, left_down, right_up, right_down
    return false;
}
