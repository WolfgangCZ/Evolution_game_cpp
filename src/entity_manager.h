#pragma once

#include <vector>

#include "animal.h"


// create more buffers and wire them together
// main buffer for all entities
// buffer for only animals
// buffer for only plants
// etc

class GameApp;

class EntityManager
{
    public:
        // it might be faster in the future to create entity map
        EntityManager(GameApp *game);
        int last_id = 0;
        void add_animal();
        void add_animal(const std::shared_ptr<Animal> &animal);
        void remove_entity(const std::shared_ptr<Animal> &animal);
        void update();
        int get_new_id();
        std::vector<std::shared_ptr<Entity>> &get_all_entities();
        const std::vector<std::shared_ptr<Entity>> &get_all_entities() const;
        GameApp *game_app;

    private:
        std::vector<std::shared_ptr<Entity>> entities;
};
