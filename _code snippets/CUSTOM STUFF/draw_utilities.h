#ifndef DRAW_UTILITIES_H
#define DRAW_UTILITIES_H

#include "raylib.h"

struct DrawCustomGrid
{
    // fill window with grid 
    void set_window_grid(int window_width, int window_height, int num_w_lines);
    //draw custom grid
    void set_custom_grid(int num_columns, int num_rows, float grid_width, float grid_height);
    void draw_grid();

    float height{};
    float width{};
    int num_columns{};
    int num_rows{};
    Color color {GRAY};
};

#endif //DRAW_UTILITIES_H