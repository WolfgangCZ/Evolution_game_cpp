#pragma once

#include "raylib.h"
#include "basic_config.h"
#include "entity_manager.h"
#include "player_control.h"
#include "custom_types.h"
#include "renderer.h"


class GameApp
{
    private:
        sh_ptr<EntityManager> entity_manager;
        sh_ptr<PlayerControl> player_control;
        // PhysicsEngine physics_engine;
        Renderer renderer;
        // AudioManager audio_manager;
        // AIController ai_controller;
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
