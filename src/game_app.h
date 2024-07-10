#pragma once

#include "raylib.h"
#include "basic_settings.h"
#include "entity_manager.h"
#include "basic_settings.h"
#include "game_state_manager.h"
#include "custom_types.h"


class GameApp
{
    private:
        s_ptr<EntityManager> entity_manager;
        Config config;
        // PhysicsEngine physics_engine;
        // Renderer renderer;
        // AudioManager audio_manager;
        // AIController ai_controller;
        PlayerControl player_control;
        // InputManager input_manager;
        // EnvironmentManager environment_manager;
        // Debugger debugger;

    public:
        GameApp();
        ~GameApp();
        void init();
        void run_game_loop();
        void update(float delta_time);
        void render();
        void run_debugger();
};
