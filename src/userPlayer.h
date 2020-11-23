#pragma once
#include "Player.h"
#include "Board.h"
#include "utils.h"

class userPlayer : public Player {
public:
    userPlayer(Board &gameBoard, int id);

    void makeFirstMove(int* move);

    void makeMoves(int* moves);

    void updateUI();

private:

    int cursorPos;
    int UIcursorPos;
    int candidate1Pos;
    int candidate2Pos;
    Board& currentBoard;

    void updateCursor(char input);
};
