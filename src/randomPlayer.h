#pragma once
#include "Player.h"
#include "Board.h"
#include <cstdlib>

class randomPlayer : public Player {
public:
    randomPlayer(Board &gameBoard, int id);

    void makeFirstMove(int* move);

    void makeMoves(int* moves);

    void updateUI();

private:

    Board& currentBoard;
};
