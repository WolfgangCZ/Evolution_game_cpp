#include "stdio.h"
#include "../raylib/raylib.h"
#include "../raylib/rlgl.h"
#include "../raylib/raymath.h"

#define WIN_H 900
#define WIN_W 1600
#define FRICTION 0.98
#define MOVEMENT_FORCE 1*1000*1000
#define BASE_CELL_SIZE 10

typedef struct Cell{
    Rectangle body;
    Vector2 movement; 
    float rotation; //+clockwise, RADs
    Color color;
} Cell;

// in RAD
float rotation(Vector2 direction) 
{
    return Vector2Angle((Vector2){0,0}, direction); 
}

void control_cell(Cell *cell, float force)
{
    if(IsKeyDown(KEY_W))
    {
        cell->movement = Vector2AddValue(cell->movement, force/(cell->body.x*cell->body.y));
    }
    if(IsKeyDown(KEY_S))
    {
        cell->movement = Vector2AddValue(cell->movement, -force/(cell->body.x*cell->body.y));
    }
    if(IsKeyDown(KEY_D))
    {
        cell->rotation += force/(cell->body.x*cell->body.y);
    }
    if(IsKeyDown(KEY_A))
    {
        cell->rotation -= force/(cell->body.x*cell->body.y);
    }
}

void update_cell(Cell *cell)
{
    Vector2 new_pos = Vector2Add((Vector2){cell->body.x, cell->body.y}, cell->movement);
    cell->body.x = new_pos.x;
    cell->body.y = new_pos.y;
    cell->movement = Vector2Scale(cell->movement, FRICTION);
    cell->rotation *= FRICTION;
}

void draw_cell(Cell *cell)
{
    Vector2 center = {cell->body.x + cell->body.height/2, cell->body.y + cell->body.height/2}; 
    float angle = Vector2Angle((Vector2){0,0}, cell->movement);
    Vector2 face = Vector2Add(center, cell->movement);
    DrawRectanglePro(cell->body, (Vector2){0.0f,0.0f}, angle, cell->color);
    DrawLineV(center, Vector2Add(center,cell->movement), WHITE);
}

typedef struct RectGrid{
    float cell_size;
} RectGrid;

void draw_grid()
{
        
}

typedef struct GridCell{
    float size;
} GridCell;

typedef struct AdjacentCells{
    GridCell *cell; //upper left is first, bottom right eight
    int len;
} AdjacentCells;

typedef struct Grid{
    GridCell *cell;
    AdjacentCells *adjacent; // cells around this one
    int count;
} Grid;

void init_grid()
{

}

int main ()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int window_width = 1600;
    const int window_height = 900;

    InitWindow(window_width, window_height, "Splint life");

    Rectangle rect = {
        .x = (float)WIN_W/2,
        .y = (float)WIN_H/2,
        .width = 10,
        .height = 10
    }; 
    Cell cell = {
        .body = rect,
        .movement = (Vector2){0,0},
        .direction = (Vector2){}
        .rotation = 0,
        .color = RED,
    };

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(30);
    Color GAME_GRAY = {40,40,40,255};
    Vector2 mouse_world_coord = {0.0f, 0.0f};


    while (!WindowShouldClose())
    {
        mouse_world_coord = GetScreenToWorld2D(GetMousePosition(), camera);

        if (IsMouseButtonDown(MOUSE_MIDDLE_BUTTON))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);
            camera.target = Vector2Add(camera.target, delta);
        }

        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            camera.offset = GetMousePosition();
            camera.target = mouse_world_coord;
            float scale = 0.2f*wheel;
            camera.zoom = Clamp(expf(logf(camera.zoom)+scale), 0.125f, 64.0f);
        }

        BeginDrawing();
            ClearBackground(GAME_GRAY);
            BeginMode2D(camera);

            control_cell(&cell, MOVEMENT_FORCE);
            update_cell(&cell);
            draw_cell(&cell);

            draw_grid();

            EndMode2D();

            DrawTextEx(
                GetFontDefault(), 
                TextFormat("[%i, %i]", GetMouseX(), GetMouseY()), 
                Vector2Add(GetMousePosition(), (Vector2){ -44, -40 }), 
                10, 
                2, 
                RAYWHITE
                );
            DrawTextEx(
                GetFontDefault(), 
                TextFormat("[%i, %i]", (int)(mouse_world_coord.x), (int)(mouse_world_coord.y)), 
                Vector2Add(GetMousePosition(), (Vector2){ -44, -20 }), 
                10, 
                2, 
                RAYWHITE
                );
        printf("cell movement x: %f:.3, y: %f:.3\n", cell.movement.x, cell.movement.y);        
        printf("cell movement x: %f:.3, y: %f:.3\n", cell.movement.x, cell.movement.y);        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
