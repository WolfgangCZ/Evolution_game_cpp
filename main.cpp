#include <iostream>
#include "game_app.h"

int main()
{
    GameApp game;
    std::cout << "Game started" << std::endl;
    game.run();
    std::cout << "Game ended" << std::endl;
    return 0;
}
