#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "raylib.h"
#include "world.h"

void keyboard_controls(float &forward_force, float &rotation_force,  WorldPopulation &all_animals);

#endif //KEYBOARD_H