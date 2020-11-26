#pragma once
#include "Player.h"
#include "Board.h"
#include "utils.h"

/*
userPlayer Class:
    Player child class that implements UI in order to play connect 6.
*/


class userPlayer : public Player {
public:
    userPlayer(Board &gameBoard, int id);

    void makeFirstMove(int* move);

    void makeMoves(int* moves);

    void updateUI();

private:

    // board cursor
    int cursorPos;
    // menu cursor
    int UIcursorPos;

    // potential candidate positions
    int candidate1Pos;
    int candidate2Pos;

    // color of player, used when drawing screen
    // Note that this value is obtained from the Board
    int pColor;

    // updates cursor based on char input (wasd)
    void updateCursor(char input);
};
