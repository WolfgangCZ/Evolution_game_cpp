#ifndef APPWINDOW_H
#define APPWINDOW_H


#include "raylib.h"
#include "CustomMenu.h"
#include <iostream>

namespace EvoGame
{
    class MainAppLoop
    {
    private:
        int window_width = 800;
        int window_height = 600;
        const char *game_title = "EVOLUTION GAME";
        int fps = 60;

    public:
        MainAppLoop();

        ~MainAppLoop();

        void Loop();

        void SetWindowWith(int width);
        void SetWindowHeight(int height);
        void SetGameTitle(const char * title);
        void SetFPS(int value);
        
    }; //end of class

}; // namespace EvoGame

#endif // APPWINDOW_H
