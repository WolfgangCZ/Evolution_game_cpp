#pragma once

#include <memory>

#include "raylib.h"
#include "player_handler.h"


class KeyboardHandler
{
    public:
        void move(PlayerHandler &player, const float &key_force, const float &rot_force)
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
        // if ( IsKeyPressed(KEY_C) )
        // {
        //     population.add_animal( std::make_shared<Animal>(Animal{}) );
        // }
        // if(IsKeyPressed(KEY_D))
        // {
        //     population.add_plant( std::make_shared<Plant>(Plant{}) );
        // }
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