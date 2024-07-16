#include "entity_manager.h"

class GameApp;

EntityManager::EntityManager()
{
}

void EntityManager::add_animal()
{
    entities.push_back(std::make_shared<Animal>());
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