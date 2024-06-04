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
#include "src/basic_settings.h"
#include "src/plant.h"
#include "src/player_handler.h"
#include "src/population.h"


int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);

    float dt = 0;

    Population population;
    std::shared_ptr<Animal> player_animal = std::make_shared<Animal>(Animal());
    PlayerHandler player_handler = PlayerHandler(player_animal);

    population.AddAnimal(player_animal);
    float key_force = 5;

    while ( !WindowShouldClose() )
    {
        BeginDrawing();
        ClearBackground(BLACK);
        dt += GetFrameTime();
        if ( IsKeyDown(KEY_UP) )
        {
            player_handler.move_player(key_force);
        }
        if ( IsKeyDown(KEY_DOWN) )
        {
            player_handler.move_player(-key_force);
        }
        if ( IsKeyDown(KEY_LEFT) )
        {
            player_handler.rotate_player(-key_force);
        }
        if ( IsKeyDown(KEY_RIGHT) )
        {
            player_handler.rotate_player(key_force);
        }
        if ( IsKeyPressed(KEY_C) )
        {
            std::cout << "adding plant" << std::endl;
            population.AddAnimal( std::make_shared<Animal>(Animal{}) );
            std::cout << "there is " << population.get_population().size() << " population now" << std::endl;
        }
        if(IsKeyPressed(KEY_D))
        {
            std::cout << "adding animal" << std::endl;
            population.AddPlant( std::make_shared<Plant>(Plant{}) );
            std::cout << "there is " << population.get_population().size() << " population now" << std::endl;
        }
        population.update();
        Vector2 player_position = player_animal->get_position();
        float player_velocity = player_animal->get_velocity();
        float player_rot_angle = player_animal->get_rot_angle();
        DrawText("DEBUG EVOGAME", 10, 10, 20, WHITE);
        DrawText(std::format("Pos X: {:.2f}", player_position.x).c_str(), 10, 30, 20, WHITE);
        DrawText(std::format("Pos Y: {:.2f}", player_position.y).c_str(), 10, 50, 20, WHITE);
        DrawText(std::format("Vel: {:.2f}", player_velocity).c_str(), 10, 70, 20, WHITE);
        DrawText(std::format("Angle: {:.2f}", player_rot_angle).c_str(), 10, 90, 20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    std::cout << "DONE! See you again later bro";
    return 0;
}
