#ifndef CUSTOM_MENU_H
#define CUSTOM_MENU_H

#include "raylib.h"

#include <string>
#include <vector>

struct Button;

class CustomFixedMenu
{
    public:
        //add whole button class with functions and tangible rectangle

        CustomFixedMenu();
        ~CustomFixedMenu();
        //set name for each tile
        void set_title(const char * name);
        void set_button_title(unsigned int pos, std::string name);
        void draw_menu();




    private:
        //basic menu for few tiles with same size
        const char *main_title {"MAIN MENU"};
        std::vector<Button> buttons;
        float title_font_size {50};
        float menu_overlap {30};
        float tiles_spacing{100};
        float frame_offset {4};
        float menu_width {};
        float menu_height {};
        float title_width {};

        void set_button_title(std::size_t pos, const char *name);

        //measure text
        Color menu_col{VIOLET};
        Color menu_frame_col{GRAY};
        Color title_color {ORANGE};

        //position of center of the menu
        float menu_x {200};
        float menu_y {200};

        
};

struct Button
{
        Button(const char *name);
        ~Button();

        void draw_button();
        bool check_click();
        bool check_hower();
        void set_title(const char *name);
        void set_xy(float x, float y);
        bool is_centered {true};

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