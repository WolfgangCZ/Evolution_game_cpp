#ifndef LIFE_FORM_H
#define LIFE_FORM_H
#include <cassert>
#include "raylib.h"
#include "physics_model.h"
#include "body_structure.h"
#include "brain.h"

class LifeForm
{
    public:
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
    ~Animal()
    {
        animal_count--;
    }
    
    //functions
    virtual void update_draw() override;            //update of drawing rectangle pro
    virtual void update_movement() override;         //update position x and y position
    virtual void update_rotation() override;         
    //getters
    unsigned int get_animal_count();
    //unsigned int get_animal_ID();

    //setters

    //members
    protected:
    static unsigned int animal_count;
    //unsigned int animal_ID {0};


    //float health {50};

};

#endif //LIFE_FORM_H

