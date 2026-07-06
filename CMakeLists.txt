cmake_minimum_required(VERSION 4.1)
project(game_of_life C)

set(CMAKE_C_STANDARD 23)

add_executable(game_of_life
        src/main.c
        src/game_of_life.h
        src/gui.h
        src/game_of_life.c
        src/gui.c
)

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