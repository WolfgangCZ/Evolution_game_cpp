#include <iostream>

#include "MainAppLoop.h"
#include "raylib.h"

namespace EvoGame
{
    //constructor with base window parameters
    MainAppLoop::MainAppLoop()
            {
                InitWindow(window_width, window_height, game_title);
                SetTargetFPS(fps);
                Loop();
            }
    MainAppLoop::~MainAppLoop()
    {};

    void MainAppLoop::Loop()
    {
        while (!WindowShouldClose())
        {
            ClearBackground(BLACK);
            BeginDrawing();
            EndDrawing();
        }
    }

    void MainAppLoop::SetWindowWith(int width)
    {
        window_width = width;
    }

    void MainAppLoop::SetWindowHeight(int height)
    {
        window_height = height;
    }

    void MainAppLoop::SetGameTitle(const char *title)
    {
        game_title = title;
    }

    void MainAppLoop::SetFPS(int value)
    {
        fps = value;
    }

    
}; // namespace EvoGame
