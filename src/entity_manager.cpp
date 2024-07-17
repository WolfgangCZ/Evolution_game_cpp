#include "entity_manager.h"
#include "custom_types.h"

class GameApp;

EntityManager::EntityManager()
{
}

void EntityManager::add_animal()
{
    m_all_entities.push_back(std::make_shared<Animal>());
}
void EntityManager::add_animal(const sh_ptr<Animal> &animal)
{
    m_all_entities.push_back(animal);
}
void EntityManager::remove_entity(const sh_ptr<Animal> &animal)
{
    for (size_t i = 0; i < m_all_entities.size(); i++)
    {
        if (m_all_entities[i] == animal)
        {
            m_all_entities.erase(m_all_entities.begin() + i);
            break;
        }
    }
}
void EntityManager::update()
{
    for (size_t i = 0; i < m_all_entities.size(); i++)
    {
        m_all_entities[i]->update();
    }
}
int EntityManager::get_new_id()
{
    last_id++;
    return last_id;
}
std::vector<sh_ptr<Entity>> &EntityManager::get_all_entities()
{
    return m_all_entities;
}
const std::vector<sh_ptr<Entity>> &EntityManager::get_all_entities() const
{
    return m_all_entities;
}