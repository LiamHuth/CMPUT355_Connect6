#pragma once
#include <iostream>

class Board {
public:
    Board();

    ~Board();

    // gets value of board at (x, y)
    char getValue(int x, int y);

    // gets value of board at board[pos]
    char getValueSingle(int pos);

    // sets value of board
    int setValue(int* moves, char value, int count);

    // returns whether or not game result has been decided
    bool decided();

    // checks board state to see if game is over, updates isDecided
    void checkGameOver();

    // prints board to terminal
    void printBoard(int cursorPos, int candidate1, int candidate2);

    // returns true if move is valid, false otherwise
    bool isValidMove(int move);

    // resets board for new game
    void reset();

    // sets colorblind options
    void colorblind();

    // fetches UI colors for player classes
    int getColor(int id);

private:

    // true if game is done, false otherwise
    bool isDecided;

    // stores last 2 moves made by player
    int* lastMoves;

    // print data for UI
    int p1Color;
    char p1Piece;
    int p2Color;
    char p2Piece;
    int candidateColor;

    // ptr to array of board values
    char* boardValues;
};
