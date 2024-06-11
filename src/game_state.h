#pragma once

enum GameState
{
    GAME_STATE_GLOBAL = 0,
    GAME_STATE_MENU_SCREEN,
    GAME_STATE_PLAYING,
    GAME_STATE_LOSE,
    GAME_STATE_WIN,
};

//global singleton
class GameStateHandler
{
    public:
        GameStateHandler()
        {}
        GameStateHandler(const GameStateHandler&) = delete;
        GameStateHandler& operator=(const GameStateHandler&) = delete;
        static GameStateHandler& get_instance()
        {
            static GameStateHandler instance;
            return instance;
        }

        void set_game_state(GameState state)
        {
            game_state = state;
        }
        GameState get_game_state()
        {
            return game_state;
        }
    private:
        GameState game_state = GAME_STATE_PLAYING;
};

static GameStateHandler &g_game_state_handler = GameStateHandler::get_instance();
