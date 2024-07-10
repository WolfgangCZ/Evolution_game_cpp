#pragma once

#include <memory>

enum class GameState
{
    GAME_STATE_GLOBAL = 0,
    GAME_STATE_MENU_SCREEN,
    GAME_STATE_PLAYING,
    GAME_STATE_LOSE,
    GAME_STATE_WIN,
};

class GameStateManager
{
    private:
        static std::shared_ptr<GameStateManager> instance;
        GameStateManager(){};
        GameStateManager(const GameState &) = delete;
        GameStateManager& operator = (const GameStateManager &) = delete;
        GameState game_state = GameState::GAME_STATE_PLAYING;

    public:
        GameState get_game_state();
        void set_game_state(const GameState &state);
        static std::shared_ptr<GameStateManager> get_instance();
};

std::shared_ptr<GameStateManager> game_state_manager = std::make_shared<GameStateManager> ();