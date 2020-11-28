#ifndef SPRITE_GAME_SPRITE_BASE_H
#define SPRITE_GAME_SPRITE_BASE_H

#include "acllib.h"
#include "global.h"
class sprite_base {
protected:
    int pos_x, pos_y;
    int width, height;
    ACL_Image *img;
    int mov_x, mov_y;
public:
    sprite_base(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y);
    virtual ~sprite_base();
    virtual void move() = 0;
    void drawSprite(int pic_width, int pic_height);
};


#endif //SPRITE_GAME_SPRITE_BASE_H
