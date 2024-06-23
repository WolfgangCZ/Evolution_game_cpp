#pragma once

#include <string>
#include <cmath>
#include <unordered_map>
#include <functional>

#include "entity.h"
#include "raylib.h"
#include "basic_settings.h"
#include "game_state_manager.h"
#include "event_listener.h"


class Animal : public Entity
{
    //structure 
    //physical attributes 
    //observers to wire it together?
    public:
        Animal();
        Animal(float x, float y, float rotation, float size);

        virtual void update() override;
        void update_position();
        void update_direction();
        void apply_friction();
        void move_forward();
        void move_backward();
        void turn_right();
        void turn_left();

        void draw_animal();
        Vector2 get_face_dir();
        Vector2 get_position();
        float get_velocity();
        float get_rot_angle();
        float get_size();
        Rectangle get_body();
        bool is_playable();

    private:
        Rectangle m_body = Rectangle{0.0f,0.0f,0.0f,0.0f};

        Vector2 m_movement_dir = Vector2{0.0f,1.0f};
        Vector2 m_face_dir = Vector2{0.0f,1.0f};

        float m_mov_strenght = 20;
        float m_rot_strenght = 1;
        float m_velocity = 0;
        float m_rot_velocity = 0;
        float m_mass = 1;

        std::string species_name = "animal";
        Color m_color = RED;

        void move(float force);
        void turn(float force);
};