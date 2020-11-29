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
    virtual void auto_move() = 0;
    void drawSprite(int pic_width = -1, int pic_height = -1);
    int get_pos_x() const;
    int get_pos_y() const;
    virtual int get_score() = 0;
    bool is_inBox();
    bool touch(const sprite_base *sprite) const;
};


#endif //SPRITE_GAME_SPRITE_BASE_H
