#pragma once

#include "raylib.h"
#include "basic_settings.h"
#include "entity_manager.h"

class GameApp
{
    public:
        EntityManager entity_manager = EntityManager(this);
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
