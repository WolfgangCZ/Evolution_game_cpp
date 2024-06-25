#pragma once

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
    public:
        GameState get_game_state();
        void set_game_state(const GameState &state);

    private:
        GameState game_state = GameState::GAME_STATE_PLAYING;
};
