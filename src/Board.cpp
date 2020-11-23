#include "Board.h"

// Board constructor: allocates and initializes board array
Board::Board() {
    boardValues = new char[361];
    for (int i = 0; i < 361; i++) { boardValues[i] = '.'; }

    lastMoves = new int[2];
    lastMoves[0] = -1;
    lastMoves[1] = -1;
}


// Board destructor: frees up memory
Board::~Board() {
    delete boardValues;
    delete lastMoves;
}

// wrapper to return whether or not the game is done
bool Board::decided() {
    return isDecided;
}

// returns the char value of a position of the board
char Board::getValue(int x, int y) {
    if (x > 19 || y > 19) {
        return boardValues[0];
    }
    return boardValues[x * 19 + y];
}

// determins if move is valid. Returns true if it is, false otherwise
bool Board::isValidMove(int move) {
    if (boardValues[move] == '.') { return true; }
    return false;
}

// updates the board state: returns 1 if successful, 0 if not successful
int Board::setValue(int* moves, char value, int count) {

    if (!isValidMove(moves[0])) { return 0; }

    boardValues[moves[0]] = value;
    lastMoves[0] = moves[0];

    // return if only one value is being updated
    if (count == 1) { return 1; }

    if (isValidMove(moves[1])) {
        boardValues[moves[1]] = value;
        lastMoves[1] = moves[1];
        checkGameOver();
        return 1;
    }
    return 0;
}

// reset board values
void Board::reset() {
    for (int i = 0; i < 361; i++) { boardValues[i] = '.'; }
    lastMoves[0] = -1;
    lastMoves[1] = -1;
    isDecided = false;
}

void Board::printBoard(int cursorPos, int candidate1, int candidate2) {

    char val;
    int index = -1;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            index++;
            // cursor background
            if (cursorPos == index) { printf("\033[100m"); }

            // check if it is temporary value
            if (candidate1 == index || candidate2 == index) {
                printf("\033[1;95m%c\033[0m ", 'x');
                continue;
            }

            // print appropriate data
            val = this->getValue(i, j);

            switch (val) {
                case '0':
                    printf("\033[1;36m%c\033[0m ", 'X');
                    break;
                case '1':
                    printf("\033[1;97m%c\033[0m ", 'X');
                    break;
                case '.':
                    printf("\033[1;90m%c\033[0m ", '.');
                    break;
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Board::checkGameOver() {

    int posDiag, negDiag, horizontal, vertical, cmpIndex;
    char playerValue, cmp;
    playerValue = boardValues[lastMoves[0]];

    // check each last move
    for (int i = 0; i < 2; i++) {
        posDiag = 0;
        negDiag = 0;
        horizontal = 0;
        vertical = 0;

        // posDiag
        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // lower left
            posDiag++;
            cmpIndex += 18;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // upper right
            posDiag++;
            cmpIndex -= 18;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        if (posDiag > 6) { isDecided = true; return; }

        // negDiag
        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // upper left
            negDiag++;
            cmpIndex -= 20;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // lower right
            negDiag++;
            cmpIndex += 20;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        if (negDiag > 6) { isDecided = true; return; }

        // horizontal
        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // right
            horizontal++;
            cmpIndex += 1;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // left
            horizontal++;
            cmpIndex -= 1;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        if (horizontal > 6) { isDecided = true; return; }

        // vertical
        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // above
            vertical++;
            cmpIndex -= 19;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        cmp = playerValue;
        cmpIndex = lastMoves[0];
        while (cmp == playerValue) {
            // below
            vertical++;
            cmpIndex += 19;
            if (cmpIndex < 0 || cmpIndex > 360) { break; }
            cmp = boardValues[cmpIndex];
        }

        if (vertical > 6) { isDecided = true; return; }
    }
}
