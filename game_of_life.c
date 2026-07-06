//
// Created by mori on 7/6/26.
//

#include "game_of_life.h"

#include <stdlib.h>

static void count_living_neighbours(int* living_neighbours, const Grid* g, int cell_idx, int total_cells);

//Initializes the datastructures and variables
bool init_grid(Grid* g, const int width, const int height)
{
    g->width = width;
    g->height = height;
    g->current_grid = calloc(width * height, sizeof(bool));
    g->next_grid = calloc(width * height, sizeof(bool));
    return g->current_grid && g->next_grid;
}

//Frees the datastructures
void free_grid(const Grid* g)
{
    free(g->current_grid);
    free(g->next_grid);
}

//Update the Grid according to the Rules
void update_grid(Grid* g)
{
    int total_cells = g->width * g->height;
    for (int cell_idx = 0; cell_idx < total_cells; cell_idx++)
    {
        if (g->current_grid[cell_idx])
        {
            //Living Cell:
            int living_neighbours = 0;
            count_living_neighbours(&living_neighbours, g, cell_idx, total_cells);

            //Rule 1: if the cell has a total of neighbours outside of [2,3], it dies
            if (living_neighbours < 2 || living_neighbours > 3) g->next_grid[cell_idx] = false;
            else g->next_grid[cell_idx] = true;
        }
        else
        {
            //Dead Cell:
            int living_neighbours = 0;
            count_living_neighbours(&living_neighbours, g, cell_idx, total_cells);

            //Rule 2: A dead cell is reborn if it has exactly 3 living neighbours
            if (living_neighbours == 3) g->next_grid[cell_idx] = true;
            else g->next_grid[cell_idx] = false;
        }
    }
    //swap the grids
    bool* temp = g->current_grid;
    g->current_grid = g->next_grid;
    g->next_grid = temp;
}

//Counts the living cells surrounding a given one
static void count_living_neighbours(int* living_neighbours, const Grid* g, const int cell_idx, int total_cells)
{
    int cell_x = cell_idx % g->width;
    int cell_y = cell_idx / g->width;

    for (int offset_y = -1; offset_y <= 1; offset_y++)
    {
        for (int offset_x = -1; offset_x <= 1; offset_x++)
        {
            if (offset_x == 0 && offset_y == 0) continue;

            int cmp_x = (cell_x + offset_x + g->width) % g->width;
            int cmp_y = (cell_y + offset_y + g->height) % g->height;

            int cmp_idx = cmp_y * g->width + cmp_x;

            if (g->current_grid[cmp_idx])
            {
                (*living_neighbours)++;
            }
        }
    }
}

//Toggle one cell in the current Grid (e.g. so you can place new cells)
void toggle_cell(Grid* g, int x, int y)
{
    const int idx = y * g->width + x;
    g->current_grid[idx] = !g->current_grid[idx];
}

void reset_grid(Grid* g)
{
    int total_cells = g->width * g->height;
    for (int cell_idx = 0; cell_idx < total_cells; cell_idx++)
    {
        g->current_grid[cell_idx] = false;
        g->next_grid[cell_idx] = false;
    }
}
