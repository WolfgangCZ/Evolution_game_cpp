#pragma once

#include "raylib.h"
#include "basic_settings.h"
#include "entity_manager.h"
#include "basic_settings.h"

class GameApp
{
    private:
        EntityManager entity_manager = EntityManager(this);
        GameStateManager game_state_manager;
        BasicSettings basic_settings;
        // PhysicsEngine physics_engine;
        // Renderer renderer;
        // AudioManager audio_manager;
        // AIController ai_controller;
        // PlayerCharacter player_character;
        // InputManager input_manager;
        // EnvironmentManager environment_manager;
        // Debugger debugger;

    public:
        GameApp();
        ~GameApp();
        void run();
        void update(float delta_time);
        void render();
        void run_debugger();
};
