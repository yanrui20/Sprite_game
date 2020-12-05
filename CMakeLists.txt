cmake_minimum_required(VERSION 3.17)
project(Sprite_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sprite_game source/main.cpp source/acllib.c source/sprite_base.cpp source/sprite_low.cpp source/sprite_usr.cpp source/sprite_blood.cpp)

target_link_libraries(Sprite_game gdi32 ole32 oleaut32 uuid winmm msimg32)