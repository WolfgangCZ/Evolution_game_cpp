#pragma once

#include <memory>
#include "animal.h"
#include "raylib.h"
#include "raylib_draw_extension.h"

// attach to animal to control it
class AnimalHandler
{
    private:
        std::shared_ptr<Animal> m_selected_animal;
    public:
        AnimalHandler(){}
        AnimalHandler(const std::shared_ptr<Animal> &player_animal)
        {
            this->m_selected_animal = player_animal;
        }
        void move_player(float force)
        {
            m_selected_animal->modify_velocity(force);
        }
        void rotate_player(float rot_force)
        {
            m_selected_animal->modify_rot_velocity(rot_force);
        }
        void update()
        {
            draw_select();
        }
        void draw_select()
        {
            if (m_selected_animal == nullptr) return;

            Rectangle rect = m_selected_animal->get_body();
            float size = rect.height;
            rect.x -= size / 2;
            rect.y -= size / 2;
            rect.width = 2*size;
            rect.height = 2*size;
            DrawRectCorners(rect, 1, rect.width/4, WHITE);
        }
        void attach_to_animal(const std::shared_ptr<Animal> &animal)
        {
            this->m_selected_animal = animal;
        }
        void detach_from_animal()
        {
            this->m_selected_animal = nullptr;
        }
        std::shared_ptr<Animal> get_animal()
        {
            return m_selected_animal;
        }
};
