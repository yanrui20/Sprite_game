//
// Created by asus on 20/11/29.
//

#ifndef SPRITE_GAME_SPRITE_BOMB_H
#define SPRITE_GAME_SPRITE_BOMB_H
#include "sprite_base.h"

class sprite_bomb : public sprite_base {
private:

public:
    sprite_bomb(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y);
    ~sprite_bomb() override;
    void auto_move() override;
    int get_score() override;
};


#endif //SPRITE_GAME_SPRITE_BOMB_H
