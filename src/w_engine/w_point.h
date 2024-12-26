#pragma once

#include <iostream>
#include "../../include/raylib.h"
#include "../../include/raymath.h"
#include "../random.h"

static size_t obj_created = 0;

namespace wEng
{
    class WPoint
    {
        private:
            Vector2 m_pos;
            Vector2 m_velocity;
            size_t id = 0;

        public:

            WPoint(const Vector2 &start_pos): 
                id(obj_created++),
                m_pos(start_pos), 
                m_velocity(Vector2{RAND_FLOAT(-100, 100), RAND_FLOAT(-100, 100)})
                {}
            void update_position(float dt)
            {
                m_pos = Vector2Add(m_pos, Vector2Scale(m_velocity, dt));            
            }
            void add_velocity(const Vector2 &vel)
            {
                m_velocity = Vector2Add(m_velocity, vel);
            }
            void render_point(float radius, Color color)
            {
                DrawCircleV(m_pos, radius, color);
            }
    };
}
