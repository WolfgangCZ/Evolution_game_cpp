#ifndef BASICBUTTON_H
#define BASICBUTTON_H

#include "raylib.h"

namespace EvoGame
{

        struct BasicButton
        {
                BasicButton(const char *name);
                ~BasicButton();

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

} // namespace EvoGame

#endif //BASICBUTTON_H