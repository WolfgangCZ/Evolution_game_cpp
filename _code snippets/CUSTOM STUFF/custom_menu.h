#ifndef CUSTOM_MENU_H
#define CUSTOM_MENU_H

#include "raylib.h"

#include <string>
#include <vector>

class CustomFixedMenu
{
    public:
        //add whole button class with functions and tangible rectangle

        CustomFixedMenu();
        ~CustomFixedMenu();
        //set name for each tile
        void set_title(std::string name);
        void set_tiles_title(unsigned int pos, std::string name);
        void draw_menu();




    private:
        //basic mane for few tiles with same size
        std::string main_title {"MAIN MENU"};
        std::vector<std::string> titles {"NEW GAME", "OPTIONS", "QUIT"};
        float font_size {40};
        float title_font_size {50};
        float tile_overlap {10};
        float menu_overlap {30};
        float button_overlap {10};
        float tiles_spacing{100};
        float frame_offset {4};
        float menu_width {};
        float menu_height {};
        float title_width {};

        //measure text

        Color font_col {WHITE};
        Color button_col{VIOLET};
        Color button_frame_col{GRAY};
        Color menu_col{BLUE};
        Color menu_frame_col{GRAY};

        //position of center of the menu
        float menu_x {400};
        float menu_y {300};

        
};

struct Button
{
        Button();
        ~Button();

        void draw_button();
        bool check_click();
        bool check_hower();
        void set_xy(float x, float y);
        bool is_centered {false};

        float pos_x {200};
        float pos_y {200};
        float width {0};
        float height {0};
        Color color {BLUE};
        Color shadow_col {GRAY};
        Color highlight {YELLOW};
        Color title_color {ORANGE};
        float shadow_offset {3};
        const char *title {"Eva smrdi jako smradoch"};
        float font_size {20};
        float button_overlap {5};

};

#endif //CUSTOM_MENU_H