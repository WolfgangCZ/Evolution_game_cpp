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

    Vector2 center = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};

    while ( !WindowShouldClose() )
    {
        std::cout << "check1" << std::endl;
        BeginDrawing();
        ClearBackground(BLACK);

        debug_mode.activate();
        debug_mode.show_player_info(player_control);
        debug_mode.show_population_info(all_animals);
        debug_mode.show_geometry(player_control);

        std::cout << "check2" << std::endl;
        Vector2 mouse_pos = GetMousePosition();
        // mouse selector - move to other class
        for (size_t i = 0; i < all_animals.get_population().size(); i++)
        {
            std::shared_ptr<Animal> selected = all_animals.get_population()[i];
            Rectangle body = selected->get_body();
            if ( CheckCollisionPointRec(mouse_pos, body) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) )
            {
                player_control.detach_from_animal();
                player_control.attach_to_animal(selected);
            }
        }

        dt += GetFrameTime();

        std::cout << "check3" << std::endl;
        keyboard_handler.others(all_animals);

        std::cout << "check4" << std::endl;

        Vector2 player_position = Vector2Zero();
        float player_velocity = 0;
        float player_rot_angle = 0;
        std::cout << "check5" << std::endl;
        if (player_control.get_animal() != nullptr)
        {
            player_position = player_control.get_animal()->get_position();
            player_velocity = player_control.get_animal()->get_velocity();
            player_rot_angle = player_control.get_animal()->get_rot_angle() * RAD2DEG;
        }
        std::cout << "check7" << std::endl;

        std::cout << "check8" << std::endl;
        all_animals.update();
        std::cout << "check9" << std::endl;
        player_control.update();
        std::cout << "check10" << std::endl;
        EndDrawing();
    }
    CloseWindow();
    std::cout << "DONE! See you again later bro";
    return 0;
}
