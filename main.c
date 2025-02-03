#include "stdio.h"
#include "raylib/raylib.h"

#define WIN_H 800
#define WIN_W 600


int main()
{
    printf("Hello world\n");
    printf("Im bored");
    InitWindow(WIN_W, WIN_H, "Hello world");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Hello world", WIN_W/2, WIN_H/2, 30, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

