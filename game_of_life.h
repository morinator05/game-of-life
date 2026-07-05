//
// Created by mori on 7/6/26.
//

#ifndef GAME_OF_LIFE_GAME_OF_LIFE_H
#define GAME_OF_LIFE_GAME_OF_LIFE_H

#include <stdbool.h>

typedef struct {
    int width;
    int height;
    bool *current_grid;
    bool *next_grid;
} Grid;

bool init_grid(Grid *g, int width, int height);
void free_grid(const Grid *g);
void update_grid(Grid *g);
void toggle_cell(Grid *g, int x, int y);

#endif //GAME_OF_LIFE_GAME_OF_LIFE_H