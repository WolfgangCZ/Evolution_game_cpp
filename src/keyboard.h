#pragma once

#include <memory>

#include "raylib.h"
#include "animal_control.h"
#include "animal_buffer.h"


class KeyboardHandler
{
    public:
        void add_animal(AnimalBuffer &population)
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
};