#include <iostream>
#include <format>
#include <string>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <memory>

#include "include/raylib.h"
#include "include/raymath.h"

#include "src/organism.h"
#include "src/animal.h"
#include "src/keyboard.h"
#include "src/basic_settings.h"
#include "src/plant.h"
#include "src/animal_control.h"
#include "src/animal_buffer.h"
#include "src/debug_mode.h"

#define DEBUG 1
/*
steps to implement:
DONE 0. rework movement
- add debug class
- add animal vision 
- add autonomous movement
- add collision
*/
int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);

    float dt = 0;

    AnimalBuffer all_animals;

    AnimalControl player_control = AnimalControl();
    KeyboardHandler keyboard_handler = KeyboardHandler(); 
    DebugMode debug_mode = DebugMode();

    while ( !WindowShouldClose() )
    {
        BeginDrawing();
        ClearBackground(BLACK);

        dt += GetFrameTime();

        debug_mode.activate();
        debug_mode.show_player_info(player_control);
        debug_mode.show_population_info(all_animals);
        debug_mode.show_geometry(player_control);

        keyboard_handler.add_animal(all_animals);
        all_animals.update();

        player_control.select_player(all_animals);
        player_control.update();

        EndDrawing();
    }
    CloseWindow();
    std::cout << "DONE! See you again later bro";
    return 0;
}
