#ifndef DRAW_UTILITIES_H
#define DRAW_UTILITIES_H

#include "raylib.h"

#include <string>

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

//draw centered rectangle
void DrawCenteredRect(float x, float y, float width, float height, Color color);
void DrawCenteredRectShadow(float x, float y, float width, float height, Color color, float shadow_offset, Color shadow_color);

//draw centered text
void DrawCenteredText(std::string text, float x, float y, float font_size, Color color);

//draw centered text with rectangle
void DrawCentTextBox(std::string text, float x, float y, float font_size, Color text_color, Color box_color, float overlap);
void DrawCentTextBoxShadow(std::string text, float x, float y, float font_size, Color text_color, Color box_color, float overlap, float shadow_offset, Color shadow_color);

#endif //DRAW_UTILITIES_H