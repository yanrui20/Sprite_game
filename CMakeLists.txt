cmake_minimum_required(VERSION 3.17)
project(Sprite_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sprite_game main.cpp acllib.c sprite_base.cpp sprite_base.h sprite_low.cpp sprite_low.h sprite_usr.cpp sprite_usr.h global.h)

target_link_libraries(Sprite_game gdi32 ole32 oleaut32 uuid winmm msimg32)