#include "userPlayer.h"

/*
userPlayer Class:
    Player child class that implements UI in order to play connect 6.
*/

// constructor
userPlayer::userPlayer(Board &gameBoard, int id) : Player(gameBoard, id) {
    cursorPos = 0;
    UIcursorPos = 0;
    candidate1Pos = -1;
    candidate2Pos = -1;

    pColor = currentBoard.getColor(id);
}


// draws user UI to screen
void userPlayer::updateUI() {
    // clear screen
    system("clear");

    // print board
    currentBoard.printBoard(cursorPos, candidate1Pos, candidate2Pos);

    // UI text
    const char* textUI[2] = {"Place/Remove", "Submit"};

    // Header
    printf("\n\033[1;%dmPlayer %d's Turn\033[0m\n", pColor, playerId+1);

    // Menu options
    for (int i = 0; i < 2; i++) {
        printf("%s%s\n", (i == UIcursorPos) ? "> " : "  ", textUI[i]);
    }
}


// Gets one move from the user
void userPlayer::makeFirstMove(int* move) {
    int input;
    bool candidateChosen = false;
    while (!candidateChosen) {
        // refresh screen
        updateUI();

        // get input from user
        input = getInput();

        // if "enter"
        if (input == '\n') {
            // submit
            if (UIcursorPos == 1) {
                // canditates chosen
                if (candidate1Pos != -1) { candidateChosen = true; }
            }

            // place or remove canditate
            if (currentBoard.isValidMove(cursorPos) && UIcursorPos == 0) {
                // location is already a candidate, remove it
                if (cursorPos == candidate1Pos) { candidate1Pos = -1; }
                // location is not a canditate and is valid
                else if (candidate1Pos == -1) { candidate1Pos = cursorPos; }
            }
            continue;
        }

        // if tab is entered
        if (input == '\t') {
            UIcursorPos = (UIcursorPos + 1) % 2;
            continue;
        }

        // update cursor
        updateCursor(input);
    }

    // return candidates in moves array, clear canaditate values
    move[0] = candidate1Pos;
    candidate1Pos = -1;
    UIcursorPos = 0;
}


// gets two moves from the user
void userPlayer::makeMoves(int* moves) {
    int input;
    bool candidatesChosen = false;
    while (!candidatesChosen) {
        // refresh screen
        updateUI();

        // get input from user
        input = getInput();

        // if "enter"
        if (input == '\n') {
            // submit
            if (UIcursorPos == 1) {
                // canditates chosen
                if (candidate1Pos != -1 && candidate2Pos != -1) { candidatesChosen = true; }
            }

            // place or remove canditate
            if (currentBoard.isValidMove(cursorPos) && UIcursorPos == 0) {

                // location is already a candidate, remove it
                if (cursorPos == candidate1Pos || cursorPos == candidate2Pos) {
                    if (candidate1Pos == cursorPos) { candidate1Pos = -1; }
                    else { candidate2Pos = -1; }
                }
                // location is not a canditate and is valid
                else {
                    if (candidate1Pos == -1) {candidate1Pos = cursorPos; }
                    else if (candidate2Pos == -1) { candidate2Pos = cursorPos; }
                }
            }
            continue;
        }

        // if tab is entered
        if (input == '\t') {
            UIcursorPos = (UIcursorPos + 1) % 2;
            continue;
        }

        // update cursor
        updateCursor(input);
    }

    // return candidates in moves array, clear canaditate values
    moves[0] = candidate1Pos;
    moves[1] = candidate2Pos;
    candidate1Pos = -1;
    candidate2Pos = -1;
    UIcursorPos = 0;
}


// updates cursor based on char input (wasd)
void userPlayer::updateCursor(char input) {
    // up
    if (input == 'w') {
        if (cursorPos >= 19) { cursorPos -= 19; }
        return;
    }
    // down
    if (input == 's') {
        if (cursorPos <= 341) { cursorPos += 19; }
        return;
    }
    // right
    if (input == 'd') {
        if ((cursorPos+1) % 19 != 0 || cursorPos == 0) { cursorPos++; }
        return;
    }
    // left
    if (input == 'a') {
        if (cursorPos % 19 != 0) { cursorPos--; }
        return;
    }
    return;
}
