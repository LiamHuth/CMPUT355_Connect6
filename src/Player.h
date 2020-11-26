#pragma once
#include "Board.h"

/*
Player Class:
    Abstract class for any player class that is run within ConnectGame.
    Classes inheriting this class should have a constructor


*/
class Player {
public:

    virtual ~Player() = default;

    virtual void makeFirstMove(int* move) = 0;

    virtual void makeMoves(int* moves) = 0;

    virtual void updateUI() = 0;

protected:

    int playerId;
};
