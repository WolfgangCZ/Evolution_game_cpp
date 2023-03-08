#include "world.h"

#include <vector>



void WorldPopulation::add_animal()
{
    //std::vector<LifeForm> world_animals{};
    world_animals.push_back(Animal{});
}

void WorldPopulation::draw_animals(LifeForm *lf_pointer)
{
    lf_pointer = nullptr;
    for(size_t i {0}; i<world_animals.size(); i++)
    {
        lf_pointer = &world_animals[i];
        lf_pointer->update_draw();
    }
}

void WorldPopulation::update_animals_movement(LifeForm *lf_pointer)
{
    lf_pointer = nullptr;
    for(size_t i {0}; i<world_animals.size(); i++)
    {
        lf_pointer = &world_animals[i];
        lf_pointer->update_movement();
    }
}

void WorldPopulation::update_rotation_movement(LifeForm *lf_pointer)
{
    lf_pointer = nullptr;
    for(size_t i {0}; i<world_animals.size(); i++)
    {
        lf_pointer = &world_animals[i];
        lf_pointer->update_rotation();
    }
}