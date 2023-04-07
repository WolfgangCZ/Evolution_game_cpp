#include "custom_menu.h"

void CustomFixedMenu::set_titles(unsigned int pos, std::string name)
{
    titles[pos] = name;
}    

void CustomFixedMenu::set_offset(unsigned int offset)
{

}

void CustomFixedMenu::draw_menu()
{
    //draw frame
    DrawRectangle(menu_x+frame_offset, menu_y+frame_offset, 100, 100, menu_frame_col);
    //draw backbround
    DrawRectangle(menu_x, menu_y, 100, 100, menu_col);
}
