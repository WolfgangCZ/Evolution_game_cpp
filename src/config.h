#pragma once

#include "../include/raylib.h"

namespace GConfig
{
    struct Config
    {
        const float win_h = 900;
        const float win_w = 1600;
        const Color background_color = Color{20, 20, 20, 255};
        const float map_size = 250;
        const Vector2 gravity_force = Vector2{0.0f, 500.0f};
        const float friction = 0.9f;
    };
    static Config config = Config();
    static const int GRID_COLS = int(config.win_w / 20.0f);
    static const int GRID_ROWS = int(config.win_h / 20.0f);
}