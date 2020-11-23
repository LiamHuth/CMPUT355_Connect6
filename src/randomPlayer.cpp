#include "randomPlayer.h"

randomPlayer::randomPlayer(Board &gameBoard, int id) : currentBoard(gameBoard){
    playerId = id;
}

void randomPlayer::updateUI() {
    return;
}

void randomPlayer::makeFirstMove(int* move) {
    do {
        move[0] = rand() % 361;
    } while (!currentBoard.isValidMove(move[0]));
}

void randomPlayer::makeMoves(int* moves) {
    do {
        moves[0] = rand() % 361;
    } while (!currentBoard.isValidMove(moves[0]));

    do {
        moves[1] = rand() % 361;
    } while (!currentBoard.isValidMove(moves[1]));
}
