#pragma once
#include "Board.h"

/*
Player Class:
    Abstract class for any player class that is run within ConnectGame.\

*/
class Player {
public:

    Player(Board &gameboard, int id) : playerId(id), currentBoard(gameboard) {}

    virtual ~Player() = default;

    // returns a move (0-360) in move[0] corresponding to a position on the board
    virtual void makeFirstMove(int* move) = 0;

    // returns two moves corresponding to positions on the board
    virtual void makeMoves(int* moves) = 0;

    // draws the UI during your turn
    virtual void updateUI() = 0;

protected:

    // either player 0 or 1
    int playerId;

    // reference to the updating board object
    Board& currentBoard;
};
