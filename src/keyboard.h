#pragma once

#include <memory>

#include "raylib.h"
#include "animal_control.h"
#include "animal_buffer.h"


class KeyboardHandler
{
    public:
        void others(AnimalBuffer &population)
        {
            if ( IsKeyPressed(KEY_C) )
            {
                population.add_animal();
            }
            // if(IsKeyPressed(KEY_D))
            // {
            //     population.add_plant();
            // }
        }
        void set_debug_mode()
        {
            if (IsKeyPressed(KEY_F3))
            {
                if(debug_mode) 
                    debug_mode = 0;
                else 
                    debug_mode = 1;
            }
        }
};