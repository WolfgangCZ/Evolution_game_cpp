#ifndef WORLD_H
#define WORLD_H

#include "life_form.h"
#include <vector>

/*
world population store all living life forms as dynamic array
functions in this class serve as updates for each frame (or some cycle based on performance in future? maybe)
also there is function for dynamicaly adding new creatures and plants or inherited creatures based on reproduction
*/

class WorldPopulation
{
    public:
    WorldPopulation()
    {}
    ~WorldPopulation()
    {}
    std::vector<Animal> world_animals{};
    void add_animal();
    void draw_animals(LifeForm *lf_pointer);
    void update_animals_movement(LifeForm *lf_pointer);
    void update_rotation_movement(LifeForm *lf_pointer);

};


#endif //WORLD_H