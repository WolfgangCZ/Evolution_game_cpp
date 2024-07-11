#pragma once

struct BasicConfig
{
    float WINDOW_WIDTH;
    float WINDOW_HEIGHT;
    int FPS;
};

static const BasicConfig basic_config = {
    .WINDOW_WIDTH = 800.0f,
    .WINDOW_HEIGHT = 600.0f,
    .FPS = 60
};
