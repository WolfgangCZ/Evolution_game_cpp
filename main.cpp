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
#include "src/player_handler.h"
#include "src/animal_buffer.h"

#define DEBUG 1

int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);

    float dt = 0;

    AnimalBuffer all_animals;

    AnimalHandler animal_handler = AnimalHandler();
    KeyboardHandler keyboard_handler = KeyboardHandler(); 

    float key_force = 20;
    float rot_force = 1;

    Vector2 center = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};

    while ( !WindowShouldClose() )
    {
        std::cout << "check1" << std::endl;
        BeginDrawing();
        ClearBackground(BLACK);

        std::cout << "check2" << std::endl;
        Vector2 mouse_pos = GetMousePosition();
        for (size_t i = 0; i < all_animals.get_population().size(); i++)
        {
            std::shared_ptr<Animal> selected = all_animals.get_population()[i];
            Rectangle body = selected->get_body();
            if ( CheckCollisionPointRec(mouse_pos, body) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) )
            {
                animal_handler.detach_from_animal();
                animal_handler.attach_to_animal(selected);
            }
        }


        dt += GetFrameTime();

        std::cout << "check3" << std::endl;
        keyboard_handler.set_debug_mode();
        keyboard_handler.move(animal_handler, key_force, rot_force);
        keyboard_handler.others(all_animals);

        std::cout << "check4" << std::endl;

        Vector2 player_position = Vector2Zero();
        float player_velocity = 0;
        float player_rot_angle = 0;
        std::cout << "check5" << std::endl;
        if (animal_handler.get_animal() != nullptr)
        {
            player_position = animal_handler.get_animal()->get_position();
            player_velocity = animal_handler.get_animal()->get_velocity();
            player_rot_angle = animal_handler.get_animal()->get_rot_angle() * RAD2DEG;
        }
        std::cout << "check7" << std::endl;

        if (debug_mode)
        {
            DrawText("DEBUG EVOGAME", 10, 10, 20, WHITE);
            DrawText(std::format("Pos X: {:.2f}", player_position.x).c_str(), 10, 30, 20, WHITE);
            DrawText(std::format("Pos Y: {:.2f}", player_position.y).c_str(), 10, 50, 20, WHITE);
            DrawText(std::format("Vel: {:.2f}", player_velocity).c_str(), 10, 70, 20, WHITE);
            DrawText(std::format("Angle: {:.2f}", player_rot_angle).c_str(), 10, 90, 20, WHITE);
            DrawText(std::format("Population: {}", all_animals.get_population().size()).c_str(), 10, 110, 20, WHITE);
            DrawCircle(center.x, center.y, 2, GREEN);
            DrawLine(center.x, center.y, player_position.x, player_position.y, GREEN);
        }    
        std::cout << "check8" << std::endl;
        all_animals.update();
        std::cout << "check9" << std::endl;
        animal_handler.update();
        std::cout << "check10" << std::endl;
        EndDrawing();
    }
    CloseWindow();
    std::cout << "DONE! See you again later bro";
    return 0;
}
