#pragma once

#include <memory>
#include "animal.h"

// attach to animal to control it
class PlayerHandler
{
    private:
        std::shared_ptr<Animal> m_player_animal;
    public:
        PlayerHandler(std::shared_ptr<Animal> player_animal)
        {
            this->m_player_animal = player_animal;
        }
        void move_player(float force)
        {
            m_player_animal->modify_velocity(force);
        }
        void rotate_player(float rot_force)
        {
            m_player_animal->modify_rot_velocity(rot_force);
        }
};
