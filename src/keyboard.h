#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "raylib.h"
#include "world.h"

/*
this function is temporary to clean main pemporarily
kayboard function should be somewhere else to get rid of passing all these parameters in function, cause when the 
algorithm gets big the list of parameteres gonna get huge
*/

void keyboard_controls(float &forward_force, float &rotation_force,  WorldPopulation &all_animals);

#endif //KEYBOARD_H