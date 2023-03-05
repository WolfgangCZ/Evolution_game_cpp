#ifndef LIFE_FORM_H
#define LIFE_FORM_H
#include <cassert>
#include "raylib.h"
#include "physics_model.h"
#include "body_structure.h"
#include "brain.h"
#include "attributes.h"

/*
classes for all lifeforms (plants and animals)
base class serve only as to call functions in animals and plants classes with pointer in one go (nothing else yet)

derived class animals
store all subclasses(not inherited classes) as parameters and to call manipulation and modifying functions 
(like updating movement and stuff) and acces point for all subclasses 
also has static value for animal count (which  could may be better in worldpopulation class)
each animal gets unique id based on order in all living and non living objects in which were created
derived class plants
NOT IMPLEMENTED
store all subclasses for plants which is gonna be structure and maybe physical attributes (but thats gonna be maybe plant_attributes)
IMPORTANT animal attributes should be renamed to animal attributes cause those attributes are gonna be wildly different from plants
*/

class LifeForm
{
    public:
    LifeForm()
    {}
    virtual ~LifeForm()
    {}


    virtual void update_draw();
    virtual void update_movement();
    virtual void update_rotation();
};

class Animal : public LifeForm
{
    public:
    //animal count

    //subclasses
    BodyStructure structure;
    PhysicsModel physics;
    //BrainWiring brain_wiring;
    //PhysicalAttributes attributes;

    //constr
    Animal()
    {
        animal_count++;
    }
    virtual ~Animal()
    {
        animal_count--;
    }
    
    //functions
    virtual void update_draw() override;            //update of drawing rectangle pro
    virtual void update_movement() override;         //update position x and y position
    virtual void update_rotation() override;         
    //getters
    unsigned int get_animal_count(); //doesnt work properly with implemented dyn array of all animals
    //unsigned int get_animal_ID();

    //setters

    //members
    protected:
    static unsigned int animal_count;
    //unsigned int animal_ID {0};


    //float health {50};

};

#endif //LIFE_FORM_H

