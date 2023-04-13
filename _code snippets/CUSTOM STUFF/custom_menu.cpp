#include "custom_menu.h"
#include "draw_utilities.h"

#include <cstring>
#include <string>
#include <vector>

CustomFixedMenu::CustomFixedMenu()
{
    buttons.push_back(Button{"NEW GAME"});
    buttons.push_back(Button{"OPTIONS"});
    buttons.push_back(Button{"QUIT"});
    if(buttons.size() != 0)
    {
        if(tiles_spacing < (buttons[0].height))
            tiles_spacing = buttons[0].height;
        
        title_width = MeasureText(main_title, title_font_size);

        //chooosing the longest button and adjusting menu width
        menu_width = title_width + 2*menu_overlap;
        for(std::size_t i{1}; i < buttons.size(); i++)
        {
            if(buttons[i].width > (menu_width - 2*menu_overlap))
                menu_width = buttons[i].width + 2*menu_overlap;
        }
        //adjusting menu height
        menu_height = tiles_spacing*(buttons.size()-1) + 3*menu_overlap + buttons[0].height;
    }
}
CustomFixedMenu::~CustomFixedMenu()
{

}

void CustomFixedMenu::set_title(const char *name)
{
    main_title = name;
}   

void CustomFixedMenu::set_button_title(unsigned int pos, const char* name)
{
    buttons[pos].set_title(name);
}    


void CustomFixedMenu::draw_menu()
{
    //draw menu rectangle
    DrawCenteredRectShadow(menu_x, menu_y, menu_width + 2*menu_overlap, menu_height+menu_overlap+title_font_size, menu_col, frame_offset, menu_frame_col);
    //drar main menu title
    DrawCenteredText(main_title, menu_x , menu_y - menu_height/2 + menu_overlap - title_font_size/2, title_font_size, title_color);
    //buttons with text

    for(std::size_t i {}; i< buttons.size(); i++)
    {
        buttons[i].pos_x = menu_x;
        buttons[i].pos_y = menu_y - menu_y/2 + 2* menu_overlap + i*tiles_spacing /*+ MeasureText(main_title, title_font_size)*/;
        buttons[i].draw_button();
    }
}
//------------------------------------------
//button class methods
//-----------------------------------------
//constructors
Button::Button(const char *name) : title(name)
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
    else DrawRectangleRec(shadow, shadow_col);

    if(check_click() == true)
        DrawRectangleRec(button, WHITE);
    else DrawRectangleRec(button, color);

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

void Button::set_title(const char* name)
{
    title = name;
}

void Button::set_xy(float x, float y)
{
    pos_x = x;
    pos_y = y;
}
