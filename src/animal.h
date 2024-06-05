#pragma once

#include <string>
#include <cmath>

#include "raylib.h"
#include "organism.h" 
#include "basic_settings.h"

class Animal : public Organism
{
    //structure 
    //physical attributes 
    //observers to wire it together?
    private:
        Rectangle m_body = Rectangle{0.0f,0.0f,0.0f,0.0f};

        Vector2 m_direction = Vector2{0.0f,1.0f};

        float m_velocity = 0;
        float m_rot_velocity = 0;

        std::string species_name = "animal";
        Color m_color = RED;

        float m_mass = 1;

    public:
        Animal();
        Animal(float x, float y, float rotation, float size);

        virtual void update() override;
        void update_position();
        void update_direction();
        void apply_friction();

        void draw_animal();
        void modify_velocity(float force);
        void modify_rot_velocity(float rot_force);
        Vector2 get_position();
        float get_velocity();
        float get_rot_angle();
        float get_size();
        Rectangle get_body();
};