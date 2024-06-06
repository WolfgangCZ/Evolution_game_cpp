#pragma once

enum GameState
{
    GAME_STATE_GLOBAL = 0,
    GAME_STATE_MENU_SCREEN,
    GAME_STATE_PLAYING,
    GAME_STATE_LOSE,
    GAME_STATE_WIN,
};

class GameStateHandler
{
    public:
        void set_game_state(GameState state)
        {
            game_state = state;
        }
        GameState get_game_state()
        {
            return game_state;
        }
    private:
        GameState game_state = GAME_STATE_GLOBAL;
};