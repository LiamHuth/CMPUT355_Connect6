#pragma once
#include "Board.h"

class Player {
public:

    virtual ~Player() = default;

    virtual void makeFirstMove(int* move) = 0;

    virtual void makeMoves(int* moves) = 0;

    virtual void updateUI() = 0;

protected:

    int playerId;
};
