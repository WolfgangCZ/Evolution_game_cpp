#include "game_app.h"

GameApp::GameApp()
{
}
GameApp::~GameApp()
{
}
void GameApp::init()
{
    entity_manager = std::make_shared<EntityManager> ();
}
void GameApp::run_game_loop()
{
    float delta_time = 0.0f;

    InitWindow(basic_config.WINDOW_WIDTH, basic_config.WINDOW_HEIGHT, "EVOLUTION");

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
    // player control
    entity_manager->update();
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