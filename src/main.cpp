#include <iostream>
#include <string>
#include "ConnectGame.h"

/*
main:
    Handles Flags, instantiates a connectGame object, and plays game
    while the player wishes to continue.
*/

int main(int argc, char* argv[])
{
    // main game object
    ConnectGame* game = new ConnectGame;

    // check flags
    for (int i = 0; i < argc; i++) {
        // use game in colorblind mode
        if (!strcmp(argv[i], "-colorblind")) {
            game->colorblindMode();
        }
    }

    // run the game loop
    while (game->isGameOn()) {
        game->start();
    }

    // clean up
    delete game;
    return 0;
}
