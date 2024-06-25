#include "game_state_manager.h"

GameState GameStateManager::get_game_state()
{
    return game_state;
}
void GameStateManager::set_game_state(const GameState &state)
{
    game_state = state;
}
