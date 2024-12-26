#pragma once

#include "../../include/raylib.h"
#include "w_point.h"

namespace wEng
{
    class WCircleParticle: public WPoint
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
            WCircleParticle(float _radius, Vector2 start_pos, Color color): 
                WPoint{start_pos}, 
                radius(_radius), 
                color(color)
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
