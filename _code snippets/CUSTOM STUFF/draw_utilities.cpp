#include "draw_utilities.h"

#include <string>

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

//draw centered rectangle
void DrawCenteredRect(float x, float y, float width, float height, Color color)
{
    DrawRectangle(x - width/2, y - height/2, width, height, color);
}
void DrawCenteredRectShadow(float x, float y, float width, float height, Color color, float shadow_offset, Color shadow_color)
{
    //shadow
    DrawCenteredRect(x+shadow_offset,y+shadow_offset,width,height,shadow_color);
    //rectangle
    DrawCenteredRect(x,y,width,height,color);
}


//draw centered text
void DrawCenteredText(std::string text, float x, float y, float font_size, Color color)
{
    DrawText(text.c_str(), x - MeasureText(text.c_str(), font_size)/2, y - font_size/2, font_size, color);
}

void DrawCentTextBox(std::string text, float x, float y, float font_size, Color text_color, Color box_color, float overlap)
{
    DrawCenteredRect(x, y, MeasureText(text.c_str(), font_size) + 2*overlap, font_size + 2*overlap, box_color);
    DrawCenteredText(text, x, y, font_size, text_color);
}

void DrawCentTextBoxShadow(std::string text, float x, float y, float font_size, Color text_color, Color box_color, float overlap, float shadow_offset, Color shadow_color)
{
    DrawCenteredRectShadow(x, y, MeasureText(text.c_str(), font_size) + 2*overlap, font_size + 2*overlap, box_color, shadow_offset, shadow_color);
    DrawCenteredText(text, x, y, font_size, text_color);
}