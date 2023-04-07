#include "raylib.h"
#include <iostream>

#include "draw_utilities.h"
#include "custom_menu.h"


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

//------------------------------------------------------------------------------------

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "New window");

    DrawCustomGrid grid;
    CustomFixedMenu menu;


    
    grid.set_window_grid(SCREEN_WIDTH, SCREEN_HEIGHT, 10);

    SetTargetFPS(60);     
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        grid.draw_grid();
        menu.draw_menu();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}