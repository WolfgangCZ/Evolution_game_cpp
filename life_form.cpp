#include <iostream>

#include "raylib.h"
#include "utilities.h"
#include "life_form.h"

unsigned int Animal::animal_count = 0;
unsigned int Plant::plant_count = 0;

void LifeForm::update_draw()
{
    assert(true);
    std::cout << "assertion failed - not allowed to call lifeform class functions ";
}
void LifeForm::update_movement()
{
    assert(true);
    std::cout << "assertion failed - not allowed to call lifeform class functions ";
}
void LifeForm::update_rotation()
{
    assert(true);
    std::cout << "assertion failed - not allowed to call lifeform class functions ";
}



void Animal::update_draw()
{
    DrawRectanglePro
    (
        structure.get_centered_rect(), 
        Vector2{structure.get_size()/2, structure.get_size()/2}, 
        physics.get_direction()*180/PI,
        structure.get_color()
    );
   // DrawRectangleRec(structure.get_rectangle(),structure.get_color());
}
void Animal::update_movement()
{
    structure.add_x(calculate_x_from_orto(physics.get_velocity(), physics.get_direction())); //minus because head down is +
    structure.add_y(-(calculate_y_from_orto(physics.get_velocity(), physics.get_direction())));
}

void Animal::update_rotation()
{
    physics.add_direction(physics.get_rot_velocity());
    if(physics.get_direction()>2*PI)
    {
        physics.add_direction(-2*PI);
    }
    else if(physics.get_direction()<0)
    {
        physics.add_direction(2*PI);
    }
}

unsigned int Animal::get_animal_count()
{
    return animal_count;
}