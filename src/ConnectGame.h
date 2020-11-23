#pragma once
#include <iostream>
#include <unistd.h>
#include "termios.h"
#include "Board.h"
#include "Player.h"
#include "userPlayer.h"
#include "randomPlayer.h"
#include "utils.h"

class ConnectGame {
public:
    ConnectGame();

    ~ConnectGame();

    // starts game loop
    void start();

    // checks if game is running
    bool isGameOn();

private:
    // used to save state of original terminal
    struct termios oldterminal;

    // current board state
    Board boardState;

    // game state
    bool gameOn;

};
