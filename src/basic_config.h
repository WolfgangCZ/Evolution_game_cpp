#pragma once

struct BasicConfig
{
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int FPS;
    float SIZE_MULTIPLIER;
};

static const BasicConfig basic_config = {
    .WINDOW_WIDTH = 800,
    .WINDOW_HEIGHT = 600,
    .FPS = 60,
    .SIZE_MULTIPLIER = 10,
};
