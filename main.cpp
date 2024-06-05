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
#include "src/population.h"

#define DEBUG 1

int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);

    float dt = 0;

    Population population;
    std::shared_ptr<Animal> player_animal = std::make_shared<Animal>(Animal());
    PlayerHandler player_handler = PlayerHandler(player_animal);
    KeyboardHandler keyboard_handler = KeyboardHandler(); 

    population.add_animal(player_animal);
    float key_force = 20;
    float rot_force = 1;

    Vector2 center = {WINDOW_WIDTH/2, WINDOW_HEIGHT/2};

    while ( !WindowShouldClose() )
    {
        BeginDrawing();
        ClearBackground(BLACK);

        dt += GetFrameTime();

        keyboard_handler.set_debug_mode();
        keyboard_handler.move(player_handler, key_force, rot_force);

        Vector2 player_position = player_animal->get_position();
        float player_velocity = player_animal->get_velocity();
        float player_rot_angle = player_animal->get_rot_angle() * RAD2DEG;


        if (debug_mode)
        {
            DrawText("DEBUG EVOGAME", 10, 10, 20, WHITE);
            DrawText(std::format("Pos X: {:.2f}", player_position.x).c_str(), 10, 30, 20, WHITE);
            DrawText(std::format("Pos Y: {:.2f}", player_position.y).c_str(), 10, 50, 20, WHITE);
            DrawText(std::format("Vel: {:.2f}", player_velocity).c_str(), 10, 70, 20, WHITE);
            DrawText(std::format("Angle: {:.2f}", player_rot_angle).c_str(), 10, 90, 20, WHITE);
            DrawText(std::format("Population: {}", population.get_population().size()).c_str(), 10, 110, 20, WHITE);
            DrawCircle(center.x, center.y, 2, GREEN);
            DrawLine(center.x, center.y, player_position.x, player_position.y, GREEN);
        }    
        population.update();
        player_handler.update();
        EndDrawing();
    }
    CloseWindow();
    std::cout << "DONE! See you again later bro";
    return 0;
}
