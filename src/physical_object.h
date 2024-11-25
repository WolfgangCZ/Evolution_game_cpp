#pragma once

#include <iostream>
#include "../include/raylib.h"

static size_t obj_created = 0;

class PhysicsObject
{
    public:
        size_t id = 0;
        Vector2 position;
        Vector2 velocity;

        PhysicsObject(const Vector2 &start_pos): 
            id(obj_created++),
            position(start_pos), 
            velocity(Vector2{RAND_FLOAT(-100, 100), RAND_FLOAT(-100, 100)})
            {}
        void update_position(float dt)
        {
            position = Vector2Add(position, Vector2Scale(velocity, dt));            
        }
        void add_velocity(const Vector2 &vel)
        {
            velocity = Vector2Add(velocity, vel);
        }
};

