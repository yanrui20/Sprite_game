//
// Created by asus on 20/11/29.
//

#ifndef SPRITE_GAME_SPRITE_BLOOD_H
#define SPRITE_GAME_SPRITE_BLOOD_H
#include "../include/sprite_base.h"

class sprite_blood : public sprite_base {
private:
    int blood;
public:
    sprite_blood(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y, int blood);
    ~sprite_blood() override;
    void auto_move() override;
    int get_score() override;
};


#endif //SPRITE_GAME_SPRITE_BLOOD_H
