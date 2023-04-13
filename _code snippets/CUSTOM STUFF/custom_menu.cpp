#include "custom_menu.h"
#include "draw_utilities.h"

#include <cstring>
#include <string>


CustomFixedMenu::CustomFixedMenu()
{
    if(tiles_spacing < (font_size + 2*button_overlap))
    tiles_spacing = font_size + 3*button_overlap;
    title_width = MeasureText(main_title.c_str(), title_font_size);
    //chooosing the longest tile and adjusting menu width
    menu_width = MeasureText(titles[0].c_str(), font_size) + menu_overlap;
    for(std::size_t i{1}; i < titles.size(); i++)
    {
        if(MeasureText(titles[i].c_str(), font_size) > MeasureText(titles[i-1].c_str(), font_size))
        menu_width = MeasureText(titles[i].c_str(), font_size) + 2*menu_overlap;
    }
    //checking if main title isnt the biggest one
    if(menu_width < MeasureText(main_title.c_str(), title_font_size))
        menu_width = MeasureText(main_title.c_str(), title_font_size) + 2*menu_overlap;

    //adjusting menu height
    menu_height = tiles_spacing*(titles.size()-1) + 3*menu_overlap + title_font_size + button_overlap;



}
CustomFixedMenu::~CustomFixedMenu()
{

}

void CustomFixedMenu::set_title(std::string name)
{
    main_title = name;
}   

void CustomFixedMenu::set_tiles_title(unsigned int pos, std::string name)
{
    titles[pos] = name;
}    


void CustomFixedMenu::draw_menu()
{
    //draw menu rectangle
    DrawCenteredRectShadow(menu_x, menu_y, menu_width + 2*menu_overlap, menu_height+menu_overlap+title_font_size+font_size, menu_col, frame_offset, menu_frame_col);
    //drar main menu title
    DrawCenteredText(main_title, menu_x , menu_y - menu_height/2 + menu_overlap - title_font_size/2, title_font_size, font_col);
    //buttons with text

    for(std::size_t i {}; i< titles.size(); i++)
    {
        DrawCentTextBoxShadow(titles[i], menu_x, menu_y + title_font_size - tiles_spacing + i*tiles_spacing, font_size, font_col, button_col, button_overlap, frame_offset, button_frame_col);
    }
}
//------------------------------------------
//button class methods
//-----------------------------------------
//constructors
Button::Button()
{
    width = MeasureText(title, font_size) + 2 * button_overlap;
    height = font_size + 2 * button_overlap;
}
Button::~Button()
{

}

void Button::draw_button()
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
    else 
        DrawRectangleRec(shadow, shadow_col);
    if(check_click() == true)
        DrawRectangleRec(button, WHITE);
    else
        DrawRectangleRec(button, color);

    DrawText(title, button.x + button_overlap, button.y + button_overlap, font_size, title_color);
}

bool Button::check_click()
{
    if(check_hower() && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        return true;
    else 
        return false;
}

bool Button::check_hower()
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

void Button::set_xy(float x, float y)
{
    pos_x = x;
    pos_y = y;
}