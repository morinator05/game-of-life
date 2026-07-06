//
// Created by mori on 7/6/26.
//

#ifndef GAME_OF_LIFE_GUI_H
#define GAME_OF_LIFE_GUI_H

#include "game_of_life.h"

void init_gui(int screen_width, int screen_height, int cell_size);
void handle_gui_input(Grid *g, int cell_size, bool *paused);
void draw_gui(const Grid *g, int cell_size, bool paused);
void close_gui(void);

#endif //GAME_OF_LIFE_GUI_H