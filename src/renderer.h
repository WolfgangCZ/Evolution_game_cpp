#pragma once

#include <vector>
#include "w_engine/circle.h"
#include "config.h"

namespace wEng
{
    class Renderer
    {
        private:
            const std::vector<wEng::WCircleParticle *> &m_objects;
        public:
            Renderer(const std::vector<WCircleParticle *> &objects):
                m_objects(objects)
            {}
            void render()
            {
                for (size_t i =0; i < m_objects.size(); i++)
                {
                    m_objects[i]->draw();
                }
            }
        static void draw_grid(int cols, int rows, int cell_w, int cell_h)
        {
            for (int col = 0; col < cols; col++)
            {
                DrawLine(col*cell_w, 0.0, col*cell_w, GConfig::config.win_h, LIGHTGRAY);         
                for (int row = 0; row < rows; row++)
                {
                    DrawLine(0.0, row*cell_h, GConfig::config.win_w, row*cell_h, LIGHTGRAY);
                }
            }
        }
    };
}
