#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <format>
#include <cassert>
#include <chrono>
#include <cstring>


#include "./include/raylib.h"
#include "./include/raymath.h"
#include "./src/geometry.h"
#include "./src/random.h"
#include "./src/config.h"
#include "./src/w_engine/renderer.h"
#include "./src/w_engine/grid.h"
#include "./src/w_engine/solver.h"
#include "./src/w_engine/grid.h"

struct Debug
{
    bool show_debug = true;
};



void mark_check(int num)
{
    std::cout << "check " << num << std::endl;
}




const float MAX_BALL_RADIUS = 5.0f;
const Vector2 CENTER = Vector2{GConfig::config.win_w/2, GConfig::config.win_h/2}; 
const Vector2 START_POS = Vector2{100, 300}; 
const Color CONTAINER_COLOR = GRAY;
const int SUB_STEPS = 1;
const int CONTAINER_RADIUS = GConfig::config.win_h * 0.95 * 0.5;

template<typename T>
void safe_clear(std::vector<T> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        delete vector[i]; 
    }
    vector.clear();
}

std::string _float_label(std::string label, float value)
{
    return std::format("{}: {:.2f}", label, value);
}
std::string _int_label(std::string label, int value)
{
    return std::format("{}: {}", label, value);
}
int main()
{
    std::cout << "START" << std::endl;
    InitWindow(GConfig::config.win_w, GConfig::config.win_h, "HELLO WORLD");
    std::vector<wEng::CircleObject *> all_objects;
    all_objects.reserve(10000);
    wEng::WSolver solver = wEng::WSolver{all_objects};
    solver.set_substeps(SUB_STEPS);
    wEng::Renderer renderer = wRen::Renderer(all_objects);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // auto start = std::chrono::high_resolution_clock::now();
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(GConfig::config.background_color);
        wRen::draw_grid(wEng::GRID_COLS, 
                        wEng::GRID_ROWS, 
                        wEng::GRID_BOX_W, 
                        wEng::GRID_BOX_H
                        );

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_A))
        {
            const Vector2 start_pos = Vector2(GetMousePosition());
            Color color = Color{RAND_CHAR, RAND_CHAR, RAND_CHAR, 255};
            all_objects.push_back(new wEng::CircleObject{RAND_FLOAT(2, (int)MAX_BALL_RADIUS), start_pos, color});
        }
        if (IsKeyPressed(KEY_C))
        {
            safe_clear(all_objects);
        }
        // TODO: take into account out of bounds objects
        solver.update_positions(dt);
        solver.apply_boundary();
        solver.apply_collision();
        solver.update();
        renderer.render();
        DrawText(_int_label("Objects count: ", all_objects.size()).c_str(), 20, 20, 10, WHITE);
        DrawText(_float_label("FPS: ", 1/dt).c_str(), 20, 40, 10, WHITE);
        if (IsKeyPressed(KEY_S))
        {
            safe_clear(all_objects);
        }
        EndDrawing();
        /*std::cout << "FPS: " << 1/dt << std::endl;*/
        /*std::cout << "Number of objects: " << all_objects.size() << std::endl;*/
    }
   

    std::cout << "DONE" << std::endl;
    return 0;
}
