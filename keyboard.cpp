
#include "keyboard.h"
#include "raylib.h"



void keyboard_controls(float &forward_force, float &rotation_force,  WorldPopulation &all_animals)
{
    if(IsKeyPressed(KEY_I))
    {
        all_animals.add_animal();
    }
    if(IsKeyPressed(KEY_O))
    {
        if(all_animals.world_animals.size()>0)
        {
            all_animals.world_animals.erase(all_animals.world_animals.end());
        }
    }
    if(IsKeyDown(KEY_W))
    {
        forward_force = 50;
    }
    if(IsKeyDown(KEY_S))
    {
        forward_force = -50;
    }
    if(IsKeyDown(KEY_A))
    {
        rotation_force = -1;
    }
    if(IsKeyDown(KEY_D))
    {
        rotation_force = 1;
    }
}