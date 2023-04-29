#include "CustomMenu.h"
#include "DrawTools.h"
#include "Button.h"
#include "raylib.h"


#include <cstring>
#include <string>
#include <vector>

namespace EvoGame
{

    CustomFixedMenu::CustomFixedMenu()
    {
        buttons.push_back(BasicButton{"NEW GAME"});
        buttons.push_back(BasicButton{"OPTIONS"});
        buttons.push_back(BasicButton{"QUIT"});
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

    void CustomFixedMenu::SetMenuCenter(int screen_width, int screen_height)
    {
        menu_x = screen_width/2;
        menu_y = screen_height/2;
    }


    void CustomFixedMenu::draw_menu()
    {
        //draw menu rectangle
        DrawCenteredRectShadow(menu_x, menu_y, menu_width + 2*menu_overlap, menu_height+menu_overlap+title_font_size, menu_col, frame_offset, menu_frame_col);
        //drar main menu title
        DrawCenteredText(main_title, menu_x , menu_y - menu_height/2 + menu_overlap - title_font_size/2, title_font_size, title_color);
        //buttons with text

        for(std::size_t i {0}; i< buttons.size(); i++)
        {
            buttons[i].pos_x = menu_x;
            buttons[i].pos_y = menu_y - menu_height/2 + 2* menu_overlap + i*tiles_spacing;
            buttons[i].draw_button();
        }
    }
}; //namespace EvoGame