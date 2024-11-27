#pragma once

#include "../../include/raylib.h"
#include "body.h"

namespace wEng
{
    class CircleObject: public Object
    {
        private:
            float inv_mass;
        public:
            float radius;
            float mass;
            Color color;
            void set_id(size_t id)
            {
                this->id = id;
            }
            CircleObject(float _radius, Vector2 start_pos, Color color):
                Object{start_pos}, radius(_radius), color(color)
                {
                mass = PI * radius * radius;
                    inv_mass = 1.0f / mass;
                }
            void draw()
            {
                DrawCircleV(position, radius, color); 
            };
            float get_inv_mass() const
            {
                return inv_mass;
            }
    };
}