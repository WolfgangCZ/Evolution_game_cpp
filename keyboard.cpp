
#include "keyboard.h"
#include "raylib.h"

void keyboard_controls(float &forward_force, float &rotation_force,  WorldPopulation &all_animals)
{
    if(IsKeyPressed(KEY_Y))
    {
        all_animals.add_animal();
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