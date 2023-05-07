#include <iostream>

#include "MainAppLoopTESTER.h"
#include "raylib.h"

namespace EvoGame
{
    //constructor with base window parameters
    MainAppLoopTESTER::MainAppLoopTESTER()
            {
                InitWindow(window_width, window_height, game_title);
                SetTargetFPS(fps);
                Loop();
            }
    MainAppLoopTESTER::~MainAppLoopTESTER()
    {};

    void MainAppLoopTESTER::Loop()
    {
        while (!WindowShouldClose())
        {
            ClearBackground(BLACK);
            //--------------------------APP LOOP-----------------------

                CustomFixedMenu mainMenu;
                mainMenu.SetMenuCenter(window_width, window_height);
                mainMenu.draw_menu();
                if(!mainMenu.CheckButtonClick(0))
                {
                    
                }
            //--------------------------APP LOOP-----------------------
            BeginDrawing();
            EndDrawing();

        }
    }


    void MainAppLoopTESTER::SetWindowWith(int width)
    {
        window_width = width;
    }

    void MainAppLoopTESTER::SetWindowHeight(int height)
    {
        window_height = height;
    }

    void MainAppLoopTESTER::SetGameTitle(const char *title)
    {
        game_title = title;
    }

    void MainAppLoopTESTER::SetFPS(int value)
    {
        fps = value;
    }

    
}; // namespace EvoGame
