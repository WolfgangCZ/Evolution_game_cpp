#include "draw_utilities.h"

// fill window with grid 
void DrawCustomGrid::set_window_grid(int window_width, int window_height, int space)
{
    width = space;
    height = space;
    num_columns = static_cast<int>(window_width/space);
    num_rows = static_cast<int>(window_height/space);
}
//draw custom grid
void DrawCustomGrid::set_custom_grid(int num_col, int num_r, float grid_width, float grid_height)
{
    width = grid_width;
    height = grid_height;
    num_columns = num_col;
    num_rows = num_r;
}

void DrawCustomGrid::draw_grid()
{
    //draw vertical lines
    for(int i {0}; i<num_columns; i++)
    {
        DrawLine(i*height, 0, i*height, height*num_rows, color);
    }
    for(int i {0}; i<num_rows; i++)
    {
        DrawLine(0, i*width, width*num_columns, i*width, color);
    }
}