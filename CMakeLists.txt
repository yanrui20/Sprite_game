cmake_minimum_required(VERSION 3.17)
project(Sprite_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sprite_game main.cpp acllib.c)

target_link_libraries(Sprite_game gdi32 ole32 oleaut32 uuid winmm msimg32)