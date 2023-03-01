#ifndef WORLD_H
#define WORLD_H

#include "life_form.h"
#include <vector>

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