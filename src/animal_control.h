#pragma once

#include <memory>
#include "animal.h"
#include "raylib.h"
#include "raylib_draw_extension.h"
#include "game_state.h"

// attach to animal to control it
class AnimalControl
{
    private:
        std::shared_ptr<Animal> m_selected_animal;
    public:
        AnimalControl(){}
        AnimalControl(const std::shared_ptr<Animal> &player_animal)
        {
            this->m_selected_animal = player_animal;
        }
        void update()
        {
            if (m_selected_animal == nullptr) return;

            draw_select();
            move_player();
            rotate_player();
        }
        void draw_select()
        {
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
        std::shared_ptr<Animal> &get_animal()
        {
            return m_selected_animal;
        }
        /*
        psuedocode: 
        function control(game_state, control_map) -> map = {key: callback}

        control would automaticaly check game_state and evaluate callbacks

        example:
        std::unordered_map<UserInputEvent, std::function<void()>> animal_movement_control = {
            {UserInputEvent::UP, std::bind(&Animal::move_forward, m_selected_animal.get())},
            {UserInputEvent::DOWN, std::bind(&Animal::move_backward, m_selected_animal.get())},
            {UserInputEvent::LEFT, std::bind(&Animal::turn_left, m_selected_animal.get())},
            {UserInputEvent::RIGHT, std::bind(&Animal::turn_right, m_selected_animal.get())}
        };
        class Control
        {
            Control(){};

            void control(UserInputEvent game_state, std::unordered_map<UserInputEvent, std::function<void()>> control_map)
            {
                if (game_state_handler.get_game_state() == game_state)
                {
                    if (control_map.find(user_input) != control_map.end())
                    {
                        control_map[user_input]();
                    }
                }
            }

        };

         */ 
        void move_player()
        {
            if (g_game_state_handler.get_game_state() == GAME_STATE_PLAYING)
            {
                if (IsKeyDown(KEY_UP))
                {
                    m_selected_animal->move_forward();
                }
                if (IsKeyDown(KEY_DOWN))
                {
                    m_selected_animal->move_backward();
                }
            }
        }
        void rotate_player()
        {
            if (g_game_state_handler.get_game_state() == GAME_STATE_PLAYING)
            {

                if (IsKeyDown(KEY_LEFT))
                {
                    m_selected_animal->turn_left();
                }
                if (IsKeyDown(KEY_RIGHT))
                {
                    m_selected_animal->turn_right();
                }
            }
        }
        void select_player(AnimalBuffer &all_animals)
        {
            if ( IsMouseButtonPressed(MOUSE_LEFT_BUTTON) )
            {
                Vector2 mouse_pos = GetMousePosition();
                for (size_t i = 0; i < all_animals.get_population().size(); i++)
                {
                    std::shared_ptr<Animal> selected = all_animals.get_population()[i];
                    Rectangle body = selected->get_body();
                    if ( CheckCollisionPointRec(mouse_pos, body) )
                    {
                        detach_from_animal();
                        attach_to_animal(selected);
                        break;
                    }
                }
            }
        }
};
