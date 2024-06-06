#pragma once

#include <memory>

#include "raylib.h"
#include "player_handler.h"
#include "animal_buffer.h"


class KeyboardHandler
{
    public:
        void move(AnimalHandler &player, const float &key_force, const float &rot_force)
        {
            if ( IsKeyDown(KEY_UP) )
            {
                player.move_player(key_force);
            }
            if ( IsKeyDown(KEY_DOWN) )
            {
                player.move_player(-key_force);
            }
            if ( IsKeyDown(KEY_LEFT) )
            {
                player.rotate_player(-rot_force);
            }
            if ( IsKeyDown(KEY_RIGHT) )
            {
                player.rotate_player(rot_force);
            }
        }
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