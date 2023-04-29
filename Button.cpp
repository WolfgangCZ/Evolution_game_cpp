#include "Button.h"

namespace EvoGame
{
    //------------------------------------------
    //button class methods
    //-----------------------------------------
    //constructors
    BasicButton::BasicButton(const char *name) : title(name)
    {
        width = MeasureText(title, font_size) + 2 * button_overlap;
        height = font_size + 2 * button_overlap;
    }

    BasicButton::~BasicButton()
    {

    }

    void BasicButton::draw_button()
    {
        Rectangle button {pos_x, pos_y, width, height};
        Rectangle shadow {pos_x + shadow_offset, pos_y + shadow_offset, width, height};

        if(is_centered == true)
        {
            button.x -= width/2; 
            button.y -= height/2; 
            shadow.x -= width/2; 
            shadow.y -= height/2; 
        }
        if(check_hower() == true)
            DrawRectangleRec(shadow, highlight);
        else DrawRectangleRec(shadow, shadow_col);

        if(check_click() == true)
            DrawRectangleRec(button, WHITE);
        else DrawRectangleRec(button, color);

        DrawText(title, button.x + button_overlap, button.y + button_overlap, font_size, title_color);
    }

    bool BasicButton::check_click()
    {
        if(check_hower() && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            return true;
        else 
            return false;
    }

    bool BasicButton::check_hower()
    {
        Vector2 mouse_pos {GetMousePosition()};
        Rectangle button {pos_x, pos_y, width, height};
        if(is_centered == true)
        {
            button.x -= width/2; 
            button.y -= height/2; 
        }
        if(CheckCollisionPointRec(mouse_pos, button) == true)
            return true;
        else return false;

    }

    void BasicButton::set_title(const char* name)
    {
        title = name;
    }

    void BasicButton::set_xy(float x, float y)
    {
        pos_x = x;
        pos_y = y;
    }
}; //namespace EvoGame