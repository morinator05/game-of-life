//
// Created by mori on 7/6/26.
//

#include "game_of_life.h"

#include <stdlib.h>

//Initializes the datastructures and variables
bool init_grid(Grid *g, const int width, const int height)
{
    g->width = width;
    g->height = height;
    g->current_grid = calloc(width * height, sizeof(bool));
    g->next_grid = calloc(width * height, sizeof(bool));
    return g->current_grid && g->next_grid;
}

//Frees the datastructures
void free_grid(const Grid *g)
{
    free(g->current_grid);
    free(g->next_grid);
}

//Update the Grid according to the Rules
void update_grid(Grid *g)
{

}

//Toggle one cell in the current Grid (e.g. so you can place new cells)
void toggle_cell(Grid *g, int x, int y)
{

}