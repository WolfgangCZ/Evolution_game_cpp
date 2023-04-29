#ifndef CUSTOM_MENU_H
#define CUSTOM_MENU_H

#include "raylib.h"

#include "Button.h"
#include <string>
#include <vector>

namespace EvoGame
{
    class CustomFixedMenu
    {
        public:
            //add whole button class with functions and tangible rectangle

            CustomFixedMenu();
            ~CustomFixedMenu();
            //set name for each tile
            void set_title(const char * name);
            void set_button_title(unsigned int pos, std::string name);
            
            void set_button_title(std::size_t pos, const char *name);
            void SetMenuCenter(int screen_width, int screen_height);
            void draw_menu();


        private:
            //basic menu for few tiles with same size
            const char *main_title {"MAIN MENU"};
            std::vector<BasicButton> buttons;
            float title_font_size {50};
            float menu_overlap {30};
            float tiles_spacing{100};
            float frame_offset {4};
            float menu_width {};
            float menu_height {};
            float title_width {};



            //measure text
            Color menu_col{VIOLET};
            Color menu_frame_col{GRAY};
            Color title_color {ORANGE};

            //position of center of the menu
            float menu_x {200};
            float menu_y {200};

            
    };
}; //namespace EvoGame


#endif //CUSTOM_MENU_H