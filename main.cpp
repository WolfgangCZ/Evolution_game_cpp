#include <iostream>
#include "./include/raylib.h"

struct Config
{
    int win_h = 600;
    int win_v = 800;
};

class Game
{

};

int main()
{
    std::cout << "START" << std::endl;
    int window_width = 800;
    int window_height = 600;

    InitWindow(window_width, window_height, "HELLO WORLD");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    std::cout << "DONE" << std::endl;
    return 0;
}
