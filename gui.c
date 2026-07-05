//
// Created by mori on 7/6/26.
//

#include <raylib.h>
#include "stdlib.h"

#include "game_of_life.h"

//Initialze the window
void init_gui(int screen_width, int screen_height, int cell_size)
{
    InitWindow(screen_width, screen_height, "game-of-life");
    SetTargetFPS(15);
}

//Handle user input and update the grid accordingly
void handle_gui_input(Grid *g, bool *paused)
{
    if (IsKeyPressed(KEY_SPACE)) *paused = !*paused;

}

//Draw the current state of the grid to the window
void draw_gui(const Grid *g, int cell_size, bool paused)
{
    BeginDrawing();
    ClearBackground(BLACK);

    //This is just for testing if the whole cell thing works or not :)
    int x = rand() % g->width;
    int y = rand() % g->height;
    DrawRectangle(x * cell_size,y * cell_size,cell_size,cell_size, WHITE);

    EndDrawing();
}

//You can guess what this does
void close_gui(void)
{
    CloseWindow();
}