//
// Created by mori on 7/6/26.
//

#include <raylib.h>

#include "game_of_life.h"

void init_gui(int screen_width, int screen_height, int cell_size)
{
    InitWindow(screen_width, screen_height, "game-of-life");
    SetTargetFPS(60);
}

void handle_gui_input(Grid *g, bool *paused)
{
    if (IsKeyPressed(KEY_SPACE)) *paused = !*paused;

}

void draw_gui(const Grid *g, int cell_size, bool paused)
{
    BeginDrawing();
    ClearBackground(BLACK);

    //TODO: draw

    EndDrawing();
}

void close_gui(void)
{
    CloseWindow();
}