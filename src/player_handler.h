#pragma once

#include <memory>
#include "animal.h"
#include "raylib.h"
#include "raylib_draw_extension.h"

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
        void update()
        {
            draw_select();
        }
        void draw_select()
        {
            Rectangle rect = m_player_animal->get_body();
            float size = rect.height;
            rect.x -= size;
            rect.y -= size;
            rect.width = 2*size;
            rect.height = 2*size;
            DrawRectCorners(rect, 1, rect.width/4, WHITE);
        }
        void attach_to_animal(const std::shared_ptr<Animal>& animal)
        {
            this->m_player_animal = animal;
        }
        void detach_from_animal()
        {
            this->m_player_animal = nullptr;
        }
};
