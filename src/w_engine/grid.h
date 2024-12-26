
#pragma once

#include <list>
#include <vector>

#include "../../include/raylib.h"
#include "w_point.h"
#include "circle.h"
#include "settings.h"
#include "../config.h"

namespace wEng
{
    const float GRID_BOX_RATIO = 20.0f;
    const int GRID_COLS = int(GConfig::config.win_w / GRID_BOX_RATIO);
    const int GRID_ROWS = int(GConfig::config.win_h / GRID_BOX_RATIO);
    const float GRID_BOX_W = GConfig::config.win_w / GRID_COLS;
    const float GRID_BOX_H = GConfig::config.win_h / GRID_ROWS;

    template<typename T>
    struct GridBox
    {
        int col;
        int row;
        bool checked = false;
        std::list<T *> obj_list;
    };

    template<typename T>
    class SolverGrid
    {
        public:
            int cols;
            int rows;
            float box_w;
            float box_h;
            std::vector<std::vector<GridBox<T>>> boxes;
        
            SolverGrid():
                cols(GRID_COLS),
                rows(GRID_ROWS),
                box_w(GRID_BOX_W),
                box_h(GRID_BOX_H)
            {
                boxes.resize(cols);
                for (int col = 0; col < cols; col++)
                {
                    boxes[col].resize(rows);
                }
                std::cout << "cols: " << cols << " rows: " << rows << std::endl;
            }
            
            void clear()
            {
                for (int col = 0; col < cols; col++)
                {
                    for (int row = 0; row < rows; row++)
                    {
                        boxes[col][row].obj_list.clear();
                        boxes[col][row].checked = false;
                    }
                }
            }
    };
}
