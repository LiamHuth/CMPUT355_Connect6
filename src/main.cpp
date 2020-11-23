#include <iostream>
#include "ConnectGame.h"


int main(int argc, char* argv[])
{
    ConnectGame* game = new ConnectGame;
    while (game->isGameOn()) {
        game->start();
    }

    delete game;

    return 0;
}
