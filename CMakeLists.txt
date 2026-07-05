cmake_minimum_required(VERSION 4.1)
project(game_of_life C)

set(CMAKE_C_STANDARD 23)

add_executable(game_of_life main.c
        game_of_life.h
        gui.h
        game_of_life.c
        gui.c)

target_link_libraries(game_of_life
        PRIVATE
        raylib
        GL
        m
        pthread
        dl
        rt
        X11
)