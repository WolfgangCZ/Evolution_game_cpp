#include <iostream>
#include "./include/raylib.h"

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
