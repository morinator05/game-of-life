#include "game_of_life.h"
#include "gui.h"
#include "raylib.h"
#include "stdio.h"

int main(void)
{
    const int window_width = 800;
    const int window_height = 600;
    const int cell_size = 20;

    const int grid_width = window_width / cell_size;
    const int grid_height = window_height / cell_size;

    Grid map;
    init_grid(&map, grid_width, grid_height);
    init_gui(window_width, window_height, cell_size);

    bool paused = false;
    float update_timer = 0.0f;
    float update_rate = 0.1f;

    while (!WindowShouldClose())
    {
        handle_gui_input(&map, &paused);

        if (!paused)
        {
            update_timer += GetFrameTime();
            if (update_timer >= update_rate)
            {
                printf("updating!\n");
                update_grid(&map);
                update_timer = 0.0f;
            }
        }

        draw_gui(&map, cell_size, paused);
    }

}