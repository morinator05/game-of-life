//
// Created by mori on 7/6/26.
//

#include <stdlib.h>

#include "game_of_life.h"
#include "gui.h"
#include "raylib.h"

int main(void)
{
    const int window_width = 1280;
    const int window_height = 920;
    const int cell_size = 10;

    //Calculate the amount of Cells which can fit into the window
    const int grid_width = window_width / cell_size;
    const int grid_height = window_height / cell_size;

    Grid world;
    init_grid(&world, grid_width, grid_height);
    init_gui(window_width, window_height, cell_size);

    bool paused = true;
    bool fancy_graphics = false;
    float update_timer = 0.0f;
    float update_rate = 0.025f;

    //Main game loop
    while (!WindowShouldClose())
    {
        handle_gui_input(&world, cell_size, &paused, &fancy_graphics);

        if (!paused)
        {
            update_timer += GetFrameTime();
            if (update_timer >= update_rate)
            {
                update_grid(&world);
                update_timer = 0.0f;
            }
        }

        draw_gui(&world, cell_size, paused, fancy_graphics);
    }

    free_grid(&world);
    close_gui();
    return(EXIT_SUCCESS);
}
