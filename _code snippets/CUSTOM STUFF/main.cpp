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
    Button button;


    
    grid.set_window_grid(SCREEN_WIDTH, SCREEN_HEIGHT, 10);

    SetTargetFPS(60);     
    //---------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        grid.draw_grid();
        button.set_xy(250,250);
        //menu.draw_menu();
        button.draw_button();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}