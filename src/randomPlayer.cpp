#include "randomPlayer.h"

/*
randomPlayer Class:
    simple implementation example of a computer player. Chooses actions at
    random.
*/

// constructor
randomPlayer::randomPlayer(Board &gameBoard, int id) : Player(gameBoard, id) {}


// no need to update UI as actions take very little time
void randomPlayer::updateUI() {
    return;
}


// choose a random move, first move is on a blank board, so no need to check if
// the position is valid
void randomPlayer::makeFirstMove(int* move) {
    move[0] = rand() % 361;
}


// choose two random moves, for each one make sure the position is valid 
void randomPlayer::makeMoves(int* moves) {
    do {
        moves[0] = rand() % 361;
    } while (!currentBoard.isValidMove(moves[0]));

    do {
        moves[1] = rand() % 361;
    } while (!currentBoard.isValidMove(moves[1]));
}
