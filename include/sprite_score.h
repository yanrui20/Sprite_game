#ifndef SPRITE_GAME_SPRITE_SCORE_H
#define SPRITE_GAME_SPRITE_SCORE_H

#include "../include/sprite_base.h"

class sprite_score
        : public sprite_base {
private:
    int score;
public:
    sprite_score(int p_x, int p_y, ACL_Image *p_img, int width, int height, int mov_x, int mov_y, int score);
    ~sprite_score() override;
    void auto_move() override;
    int get_score() const;
};


#endif //SPRITE_GAME_SPRITE_SCORE_H
