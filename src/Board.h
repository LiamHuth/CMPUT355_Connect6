#pragma once
#include <iostream>

class Board {
public:
    Board();

    ~Board();

    // gets value of board at (x, y)
    char getValue(int x, int y);

    // sets value of board
    int setValue(int* moves, char value, int count);

    // returns whether or not game result has been decided
    bool decided();

    // checks board state to see if game is over, updates isDecided
    void checkGameOver();

    void printBoard(int cursorPos, int candidate1, int candidate2);

    // returns true if move is valid, false otherwise
    bool isValidMove(int move);

    // resets board for new game
    void reset();

private:
    // ptr to array of board values
    char* boardValues;

    // true if game is done, false otherwise
    bool isDecided;

    int* lastMoves;

};
