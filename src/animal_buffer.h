#pragma once

#include <vector>
#include <memory>

#include "organism.h"
#include "animal.h"
#include "plant.h"
#include "organism_buffer.h"

class AnimalBuffer : public OrganismBuffer
{
    private:
        std::vector<std::shared_ptr<Animal>> animals;
    public:
        AnimalBuffer(){}
        void set_animal(std::shared_ptr<Animal> animal)
        {
            animals.push_back(animal);
        }
        void add_animal()
        {
            animals.push_back(std::make_shared<Animal>());
        }
        void update()
        {
            for(size_t i = 0; i < animals.size(); i++)
            {
                animals[i]->update();
            }
        }
        std::vector<std::shared_ptr<Animal>> get_population()
        {
            return animals;
        }
};