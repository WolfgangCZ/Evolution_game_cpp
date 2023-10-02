#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <memory>

#include "include/raylib.h"

#define WINDOW_WIDTH    600
#define WINDOW_HEIGHT   800
#define FPS             60
#define ANIMAL_SIZE     10
#define PLANT_SIZE      30
#define DEBIG_MODE      1

class Organism
{
    public:
        void update(); 
};

class Plant : Organism
{   
    private:
        Rectangle body;
        Color color = GREEN;
        std::string species_name = "plant";
    public:
        Plant()
        {}
        Plant(float x, float y, float size) : body{Rectangle{x,y,size,size}}
        {}
        void update()
        {
            draw_plant();
        }
        void draw_plant()
        {
            DrawRectangleRec(body, color);
        }
};

class Animal : Organism
{
    private:
        Rectangle body;// = {0.0f,0.0f,0.0f,0.0f};
        Color color = RED;
        float dir_deg;
        std::string species_name = "animal";
    public:
        Animal() : body{Rectangle{
            static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT)),
            static_cast<float>(GetRandomValue(0, WINDOW_WIDTH)),
            PLANT_SIZE,
            PLANT_SIZE
        }}, dir_deg{static_cast<float>(GetRandomValue(0, 360))}
        {}
        Animal(float x, float y, float direction, float size) : body{Rectangle{x,y,size,size}}, dir_deg{direction}
        {}
        ~Animal()
        {}
        void update()
        {
            draw_animal();
        }
        void draw_animal()
        {
            DrawRectanglePro(body, Vector2{0, 0}, 45, color);
        }
};

int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);
    float dt;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        dt = GetFrameTime();
        std::vector<std::shared_ptr<Organism>> population;
        if(IsKeyPressed(KEY_A))
        {
            population.push_back(std::make_shared<Organism>(Animal()));
        }
        EndDrawing();
    }
    CloseWindow();

    std::cout << "DONE! See you again later bro";
    return 0;
}
