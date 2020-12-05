#ifndef SPRITE_GAME_SPRITE_LOW_H
#define SPRITE_GAME_SPRITE_LOW_H

#include "../include/sprite_base.h"

class sprite_low
        : public sprite_base {
private:
    int score;
public:
    sprite_low(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y);
    ~sprite_low() override;
    void auto_move() override;
    int get_score() override;
};


#endif //SPRITE_GAME_SPRITE_LOW_H
