#include <iostream>
#include "game_app.h"
#include "basic_config.h"

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
    std::cout << "Window width: " << basic_config.WINDOW_WIDTH << std::endl;
    std::cout << "Window height: " << basic_config.WINDOW_HEIGHT << std::endl;
    InitWindow(basic_config.WINDOW_WIDTH, basic_config.WINDOW_HEIGHT, "EVOLUTION");

    while(!WindowShouldClose())
    {
        BeginDrawing();

        delta_time = GetFrameTime() - delta_time;

        update(delta_time);
        render();
        run_debugger();
        if (IsKeyPressed(KEY_A))
            entity_manager->add_animal();
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
    renderer.render(entity_manager->get_all_entities());
}
void GameApp::run_debugger()
{
    if (IsKeyPressed(KEY_F1))
    {
        // debugger.render(*this);
    }
}