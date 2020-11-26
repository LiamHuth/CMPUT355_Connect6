#pragma once
#include "Player.h"
#include "Board.h"
#include <cstdlib>

/*
randomPlayer Class:
    simple implementation example of a computer player. Chooses actions at
    random.
*/


class randomPlayer : public Player {
public:
    randomPlayer(Board &gameBoard, int id);

    void makeFirstMove(int* move);

    void makeMoves(int* moves);

    void updateUI();
};
