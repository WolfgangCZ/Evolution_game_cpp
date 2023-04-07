#ifndef CUSTOM_MENU_H
#define CUSTOM_MENU_H

#include "raylib.h"

#include <string>
#include <vector>

class CustomFixedMenu
{
    public:
        //set name for each tile
        void set_titles(unsigned int pos, std::string name);
        void set_offset(unsigned int offset);
        void draw_menu();

    private:
        //basic mane for few tiles with same size
        std::vector<std::string> titles {"TITLE 1", "TITLE 2", "TITLE 3"};
        unsigned int button_pos {titles.size()};
        float font_size {10};
        float tile_overlap {20};
        float background_offset{20};
        float tile_offset {100};
        float frame_offset {4};

        //measure text

        Color menu_col{RED};
        Color menu_frame_col{GRAY};

        //position of left upper corner of whole menu
        float menu_x {50};
        float menu_y {50};

        
};

#endif //CUSTOM_MENU_H