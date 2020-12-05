#include <iostream>
#include "../include/global.h"
#include <ctime>
#include "../include/sprite_score.h"
#include "../include/sprite_usr.h"
#include "../include/sprite_blood.h"

void timerEvent(int id);
void keyboardEvent(int key, int event);
void eat();
void print();
void create_usr();
void create_score(sprite_score **Score, ACL_Image *p_img, int score);
void create_blood(sprite_blood **pSpriteBlood, ACL_Image *p_img, int blood);
void restart();

ACL_Image usr_img, score_img, bomb_img, game_over_img, heart_img, background_img;
sprite_score * spriteScore[MAX_SPRITE_SCORE_UP] = {nullptr};
sprite_usr * spriteUsr = nullptr;
sprite_blood * spriteBomb[MAX_BOMB] = {nullptr};
sprite_blood * spriteHeart[MAX_HEART] = {nullptr};
bool game_over = false;
int level = 1;
int direct_x = 0, direct_y = 0;
int usr_speed = USR_START_SPEED;

int Setup() {
    initWindow("Sprite Game", 350, 100, WINDOW_WIDTH, WINDOW_HEIGHT);
    loadImage("../picture/tom.bmp", &usr_img);
    loadImage("../picture/jerry.bmp", &score_img);
    loadImage("../picture/bomb.jpg", &bomb_img);
    loadImage("../picture/GAME_OVER.jpg", &game_over_img);
    loadImage("../picture/heart.jpg", &heart_img);
    loadImage("../picture/background.jpg", &background_img);
    srand(time(nullptr));
    create_usr();
    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyboardEvent);
    startTimer(0, 20);
    return 0;
}

void timerEvent(int id){
    if (game_over) return;
    level = spriteUsr->get_score() / 50 + 1;
    spriteUsr->auto_move();
    eat();
    for(auto & score : spriteScore) {
        if(score) score->auto_move();
        else create_score(&score, &score_img, SCORE_UP_SCORE);
        if (!(score->is_inBox())) {
            delete score;
            score = nullptr;
        }
    }
    for(auto & bomb : spriteBomb) {
        if(bomb) bomb->auto_move();
        else create_blood(&bomb, &bomb_img, BOMB_BLOOD);
        if (!(bomb->is_inBox())) {
            delete bomb;
            bomb = nullptr;
        }
    }
    if (level >= 2) {
        for(auto & heart : spriteHeart) {
            if(heart) heart->auto_move();
            else create_blood(&heart, &heart_img, HEART_BLOOD);
            if (!(heart->is_inBox())) {
                delete heart;
                heart = nullptr;
            }
        }
    }
    print();
}

void keyboardEvent(int key, int event) {
    if(event != KEY_DOWN && event != KEY_UP) return;
    if (event == KEY_DOWN) {
        switch(key) {
            case VK_UP:
                direct_y--;
                break;
            case VK_DOWN:
                direct_y++;
                break;
            case VK_LEFT:
                direct_x--;
                break;
            case VK_RIGHT:
                direct_x++;
                break;
            case 'W':
                usr_speed++;
                if (usr_speed > USR_MAX_SPEED)  {
                    usr_speed = USR_MAX_SPEED;
                }
                break;
            case 'S':
                usr_speed--;
                if (usr_speed < USR_MIN_SPEED)  {
                    usr_speed = USR_MIN_SPEED;
                }
                break;
            case VK_ESCAPE:
                exit(0);
            case 'R':
                restart();
                break;
            default:
                break;
        }
    } else {
        switch(key) {
            case VK_UP:
                direct_y++;
                break;
            case VK_DOWN:
                direct_y--;
                break;
            case VK_LEFT:
                direct_x++;
                break;
            case VK_RIGHT:
                direct_x--;
                break;
            default:
                break;
        }
    }
    if (direct_x > 1) {
        direct_x = 1;
    }else if (direct_x < -1) {
        direct_x = -1;
    }
    if (direct_y > 1) {
        direct_y = 1;
    }else if (direct_y < -1) {
        direct_y = -1;
    }
    spriteUsr->change_mov(direct_x * usr_speed, direct_y * usr_speed);
}

void eat() {
    for (auto & score : spriteScore) {
        if (score && score->touch(spriteUsr)) {
            spriteUsr->add_score(score->get_score());
            delete score;
            score = nullptr;
        }
    }
    for (auto & bomb : spriteBomb) {
        if (bomb && bomb->touch(spriteUsr)) {
            spriteUsr->add_blood(bomb->get_blood());
            delete bomb;
            bomb = nullptr;
        }
    }
    for (auto & heart : spriteHeart) {
        if (heart && heart->touch(spriteUsr)) {
            if (spriteUsr->get_blood() < USR_BLOOD) {
                spriteUsr->add_blood(heart->get_blood());
            }
            delete heart;
            heart = nullptr;
        }
    }
}

void print() {
    beginPaint();
    clearDevice();
    // background
    putImageScale(&background_img, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    // print usr
    spriteUsr->drawSprite(RGB(255, 255, 255));
    // print score
    for (auto & Score : spriteScore) {
        if (Score) {
            Score->drawSprite(RGB(255, 255, 255));
        }
    }
    // print bomb
    for (auto & bomb : spriteBomb) {
        if (bomb) {
            bomb->drawSprite(RGB(246, 246, 246));
        }
    }
    for (auto & heart : spriteHeart) {
        if (heart) {
            heart->drawSprite(RGB(255, 255, 255));
        }
    }
    // if game over
    if(spriteUsr->get_blood() <= 0) {
        game_over = true;
        putImageScale(&game_over_img, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    // print score, blood, level
    char score_txt[20], blood_txt[20], level_txt[20], speed_txt[20], hint_txt[100];
    sprintf_s(score_txt, "Score: %d", spriteUsr->get_score());
    sprintf_s(blood_txt, "Blood: %d", spriteUsr->get_blood());
    sprintf_s(level_txt, "Level: %d", level);
    sprintf_s(speed_txt, "Your Speed: %d", usr_speed);
    sprintf_s(hint_txt, "ESC:Quit  R:Restart  W:SpeedUp  S:SpeedDown");
    setTextSize(TEXT_SIZE);
    setTextColor(BLUE);
    paintText(0, 0, score_txt);
    setTextColor(RED);
    paintText(500, 0, blood_txt);
    setTextColor(GREEN);
    paintText(1050, 0, level_txt);
    setTextColor(BLACK);
    paintText(500, WINDOW_HEIGHT - 2 * TEXT_SIZE, speed_txt);
    setTextColor(BLACK);
    paintText(335, WINDOW_HEIGHT - TEXT_SIZE, hint_txt);
    endPaint();
}

void create_usr() {
    int x = WINDOW_WIDTH / 2;
    int y = WINDOW_HEIGHT / 2;
    spriteUsr = new sprite_usr(x, y, &usr_img, PIC_SIZE, PIC_SIZE, 0, 0);
}

void create_score(sprite_score **Score, ACL_Image *p_img, int score) {
    int x = rand() % (WINDOW_WIDTH - PIC_SIZE);
    int y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
    int mov_x = 0;
    int mov_y = 0;
    while (mov_x == 0 && mov_y == 0) {
        mov_x = (rand() % 3 - 1) * SCORE_UP_SPEED;
        mov_y = (rand() % 3 - 1) * SCORE_UP_SPEED;
    }
    *Score = new sprite_score(x, y, p_img, PIC_SIZE, PIC_SIZE, mov_x, mov_y, score);
}

void create_blood(sprite_blood **pSpriteBlood, ACL_Image *p_img, int blood) {
    int x, y;
    switch (rand() % 4) {
        case 0: // up
            x = rand() % (WINDOW_WIDTH - PIC_SIZE);
            y = 0;
            break;
        case 1: // down
            x = rand() % (WINDOW_WIDTH - PIC_SIZE);
            y = WINDOW_HEIGHT - PIC_SIZE;
            break;
        case 2: // left
            x = 0;
            y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
            break;
        case 3: // right
            x = WINDOW_WIDTH - PIC_SIZE;
            y = rand() % (WINDOW_HEIGHT - PIC_SIZE);
            break;
        default:break;
    }
    int mov_x = 0;
    int mov_y = 0;
    while (mov_x == 0 && mov_y == 0) {
        mov_x = (rand() % 3 - 1) * SPEED_EVERY_LEVEL;
        mov_y = (rand() % 3 - 1) * SPEED_EVERY_LEVEL;
    }
    mov_x *= level;
    mov_y *= level;
    *pSpriteBlood = new sprite_blood(x, y, p_img, PIC_SIZE, PIC_SIZE, mov_x, mov_y, blood);
}

void restart() {
    for(auto & score : spriteScore) {
        delete score;
        score = nullptr;
    }
    for(auto & bomb : spriteBomb) {
        delete bomb;
        bomb = nullptr;
    }
    for(auto & heart : spriteHeart) {
        delete heart;
        heart = nullptr;
    }
    delete spriteUsr;
    create_usr();
    game_over = false;
    level = 1;
    direct_x = 0;
    direct_y = 0;
    usr_speed = USR_START_SPEED;
}