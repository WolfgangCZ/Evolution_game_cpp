#pragma once

#include <vector>

#include "animal.h"


class EntityManager
{
    public:
        // it might be faster in the future to create entity map
        EntityManager();
        int last_id = 0;
        void add_animal();
        void add_animal(const std::shared_ptr<Animal> &animal);
        void remove_entity(const std::shared_ptr<Animal> &animal);
        void update();
        int get_new_id();
        std::vector<std::shared_ptr<Entity>> entities; 
        std::vector<std::shared_ptr<Entity>> &get_all_entities();
        const std::vector<std::shared_ptr<Entity>> &get_all_entities() const;

    private:
        std::vector<std::shared_ptr<Entity>> entities;
};

EntityManager::EntityManager()
{
}

void EntityManager::add_animal()
{
    entities.push_back(std::make_shared<Entity>(Animal()));
}
void EntityManager::add_animal(const std::shared_ptr<Animal> &animal)
{
    entities.push_back(animal);
}
void EntityManager::remove_entity(const std::shared_ptr<Animal> &animal)
{
    for (size_t i = 0; i < entities.size(); i++)
    {
        if (entities[i] == animal)
        {
            entities.erase(entities.begin() + i);
            break;
        }
    }
}
void EntityManager::update()
{
    for (size_t i = 0; i < entities.size(); i++)
    {
        entities[i]->update();
    }
}
int EntityManager::get_new_id()
{
    last_id++;
    return last_id;
}
std::vector<std::shared_ptr<Entity>> &EntityManager::get_all_entities()
{
    return entities;
}
const std::vector<std::shared_ptr<Entity>> &EntityManager::get_all_entities() const
{
    return entities;
}

// create more buffers and wire them together
// main buffer for all entities
// buffer for only animals
// buffer for only plants
// etc
