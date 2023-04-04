#include "custom_menu.h"

void CustomMenu::set_titles(unsigned int pos, std::string name)
{
    titles[pos] = name;
}    

void CustomMenu::set_offset(unsigned int offset)
{

}

void CustomMenu::draw_menu()
{
    //draw frame
    DrawRectangle(menu_x-frame_offset, menu_y-frame_offset, 100+frame_offset*2, 100+frame_offset*2, menu_frame_col);
    //draw backbround
    DrawRectangle(menu_x, menu_y, 100, 100, menu_col);
}
