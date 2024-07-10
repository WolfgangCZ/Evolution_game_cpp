#pragma once

struct Config{
    float WINDOW_WIDTH;
    float WINDOW_HEIGHT;
    float FPS;
};

static Config config = Config{
    .WINDOW_WIDTH = 800,
    .WINDOW_HEIGHT = 600,
    .FPS = 60
};
