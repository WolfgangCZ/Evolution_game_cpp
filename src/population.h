#pragma once

#include <vector>
#include <memory>

#include "organism.h"
#include "animal.h"
#include "plant.h"

class Population
{
    private:
        std::vector<std::shared_ptr<Organism>> population;
    public:
        Population(){}
        ~Population(){}
        void AddAnimal( std::shared_ptr<Animal> new_animal )
        {
            population.push_back( new_animal );
        }
        void AddPlant( std::shared_ptr<Plant> new_plant )
        {
            population.push_back(new_plant);
        }
        void update()
        {
            for(size_t i = 0; i < population.size(); i++)
            {
                population[i]->update();
            }
        }
        std::vector<std::shared_ptr<Organism>> get_population()
        {
            return population;
        }
};