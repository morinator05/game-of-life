//
// Created by mori on 7/6/26.
//

#include "game_of_life.h"

#include <stdlib.h>

bool init_grid(Grid *g, int width, int height)
{
    g->width = width;
    g->height = height;
    g->current_grid = calloc(width * height, sizeof(bool));
    g->next_grid = calloc(width * height, sizeof(bool));
    return g->current_grid && g->next_grid;
}

void free_grid(Grid *g)
{

}

void update_grid(Grid *g)
{

}

void toggle_cell(Grid *g, int x, int y)
{

}