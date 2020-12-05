#ifndef SPRITE_GAME_SPRITE_USR_H
#define SPRITE_GAME_SPRITE_USR_H
#include "../include/sprite_base.h"

class sprite_usr : public sprite_base {
private:
    int score;
    int blood;
public:
    sprite_usr(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y);
    ~sprite_usr() override;
    void auto_move() override;
    int get_special_value() override;
    void add_score(int add);
    int get_blood() const;
    void add_blood(int a);
    void change_mov(int mov_x, int mov_y);
};


#endif //SPRITE_GAME_SPRITE_USR_H
