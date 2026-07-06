//
// Created by mori on 7/6/26.
//

#include <raylib.h>

#include "game_of_life.h"

//Initialze the window
void init_gui(int screen_width, int screen_height, int cell_size)
{
    InitWindow(screen_width, screen_height, "game-of-life");
    SetTargetFPS(60);
}

//Handle user input and update the grid accordingly
void handle_gui_input(Grid* g, int cell_size, bool* paused)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        *paused = !*paused;
        if (*paused) SetWindowTitle("Paused, press SPACE to continue!");
        else SetWindowTitle("Running, press SPACE to pause!");
    }

    if (*paused & IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        int x = GetMouseX() / cell_size;
        int y = GetMouseY() / cell_size;
        toggle_cell(g, x, y);
    }
}

//Draw the current state of the grid to the window
void draw_gui(const Grid* g, int cell_size, bool paused)
{
    BeginDrawing();
    ClearBackground(BLACK);

    int total_cells = g->width * g->height;
    for (int cell_idx = 0; cell_idx < total_cells; cell_idx++)
    {
        if (g->current_grid[cell_idx])
        {
            int x = cell_idx % g->width;
            int y = cell_idx / g->width;
            DrawRectangle(x * cell_size, y * cell_size, cell_size, cell_size, WHITE);
        }
    }

    EndDrawing();
}

//You can guess what this does
void close_gui(void)
{
    CloseWindow();
}
