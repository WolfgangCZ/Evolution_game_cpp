#ifndef APPWINDOW_H
#define APPWINDOW_H


#include "raylib.h"
#include "GlobalParManager.h"
#include <iostream>

namespace EvoGame
{
    class MainGameLoop
    {
    private:
    
        GlobalParManager Global;
    public:
        MainGameLoop();

        ~MainGameLoop();

        void Loop();

        
    }; //end of class

}; // namespace EvoGame

#endif // APPWINDOW_H
