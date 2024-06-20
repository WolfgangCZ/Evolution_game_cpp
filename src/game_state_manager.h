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
        const GameState &get_game_state() const;
        GameState &get_game_state();
        void set_game_state(GameState state);

    private:
        GameState game_state = GameState::GAME_STATE_PLAYING;
};

const GameState &GameStateManager::get_game_state() const
{
    return game_state;
}
GameState &GameStateManager::get_game_state()
{
    return game_state;
}

void GameStateManager::set_game_state(GameState state)
{
    game_state = state;
}

