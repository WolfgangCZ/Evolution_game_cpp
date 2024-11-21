#include <iostream>
#include "./src/game_app.h"

int main()
{
    GameApp game;
    std::cout << "Game started" << std::endl;

    game.init();
    game.run_game_loop();

    std::cout << "Game ended" << std::endl;

    int number = 1;

    return 0;
}
