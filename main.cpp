#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <memory>

#include "include/raylib.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600
#define FPS             60
#define ANIMAL_SIZE     10
#define PLANT_SIZE      30
#define DEBIG_MODE      1

class Organism
{
    public:
        virtual void update() = 0; 
};

class Plant : public Organism
{   
    private:
        Rectangle body;
        Color color = GREEN;
        std::string species_name = "plant";
    public:
        Plant() : body{
                Rectangle{
                    static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT)),
                    static_cast<float>(GetRandomValue(0, WINDOW_WIDTH)),
                    PLANT_SIZE,
                    PLANT_SIZE
                }
        }
        {}
        Plant(float x, float y, float size) : body{Rectangle{x,y,size,size}}
        {}
        virtual void update() override
        {
            draw_plant();
        }
        void draw_plant()
        {
            DrawRectangleRec(body, color);
        }
};

class Animal : public Organism
{
    //structure 
    //physical attributes 
    //observers to wire it together?
    private:
        Rectangle body;// = {0.0f,0.0f,0.0f,0.0f};
        Color color = RED;
        float dir_deg;
        std::string species_name = "animal";
    public:
        Animal() : body{
            Rectangle{
                    static_cast<float>(GetRandomValue(0, WINDOW_HEIGHT)),
                    static_cast<float>(GetRandomValue(0, WINDOW_WIDTH)),
                    ANIMAL_SIZE,
                    ANIMAL_SIZE
            }
        }, dir_deg{static_cast<float>(GetRandomValue(0, 360))}
        {}
        Animal(float x, float y, float direction, float size) : body{Rectangle{x,y,size,size}}, dir_deg{direction}
        {}
        ~Animal()
        {}
        virtual void update() override
        {
            drawAnimal();
        }
        void drawAnimal()
        {
            DrawRectanglePro(body, Vector2{0, 0}, dir_deg, color);
        }
        void moveBody(const float &force, const float &rotation)
        {

        }
};

class Population
{
    private:
        std::vector<std::shared_ptr<Organism>> population;
    public:
        Population(){}
        ~Population(){}
        void addAnimal( std::shared_ptr<Animal> new_animal )
        {
            population.push_back( new_animal );
        }
        void addPlant( std::shared_ptr<Plant> new_plant )
        {
            population.push_back(new_plant);
        }
        void update()
        {
            for(size_t i = 0; i < population.size(); i++)
            {
                population[i]->update();
            }
        }
        std::vector<std::shared_ptr<Organism>> get_population()
        {
            return population;
        }
};


class PlayerHandle
{
    private:
        std::shared_ptr<Animal> player_animal;
    public:
        PlayerHandle(std::shared_ptr<Animal> player_animal)
        {}
        void MovePlayer(Vector2 direction)
        {
            player_animal->moveBody(direction);
        }
};

int main ()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "DEBUG EVOGAME");
    SetTargetFPS(FPS);
    float dt = 0;
    Population population;
    std::shared_ptr<Animal> player_animal = std::make_shared<Animal>(Animal{});
    population.addAnimal(player_animal);

    while ( !WindowShouldClose() )
    {
        BeginDrawing();
        dt += GetFrameTime();
        // abstract it to a class
        if ( IsKeyPressed(KEY_C) )
        {
            std::cout << "adding plant" << std::endl;
            population.addAnimal( std::make_shared<Animal>(Animal{}) );
            std::cout << "there is " << population.get_population().size() << " population now" << std::endl;
        }
        if(IsKeyPressed(KEY_D))
        {
            std::cout << "adding animal" << std::endl;
            population.addPlant( std::make_shared<Plant>(Plant{}) );
            std::cout << "there is " << population.get_population().size() << " population now" << std::endl;
        }
        population.update();
        EndDrawing();
    }
    CloseWindow();

    std::cout << "DONE! See you again later bro";
    return 0;
}
