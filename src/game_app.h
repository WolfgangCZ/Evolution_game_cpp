#pragma once

#include "raylib.h"
#include "basic_settings.h"

class GameApp
{
    public:
        // EntityManager entity_manager;
        // GameStateHandler game_state_handler;
        // PhysicsEngine physics_engine;
        // Renderer renderer;
        // AudioManager audio_manager;
        // AIController ai_controller;
        // PlayerCharacter player_character;
        // InputManager input_manager;
        // EnvironmentManager environment_manager;
        // Debugger debugger;

        GameApp();
        ~GameApp();
        void run();
        void update(float delta_time);
        void render();
        void run_debugger();
};


GameApp::GameApp()
{
}
GameApp::~GameApp()
{
}
void GameApp::run()
{
    int WINDOW_WIDTH = 800;
    int WINDOW_HEIGHT = 600;

    float delta_time = 0.0f;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "EVOLUTION");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        delta_time = GetFrameTime() - delta_time;

        update(delta_time);
        render();
        run_debugger();

        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

}
void GameApp::update(float delta_time)
{
}
void GameApp::render()
{
}
void GameApp::run_debugger()
{
    if (IsKeyPressed(KEY_F1))
    {
        // debugger.render(*this);
    }
}