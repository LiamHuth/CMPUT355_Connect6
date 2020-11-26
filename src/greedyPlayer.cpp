#include "greedyPlayer.h"

greedyPlayer::greedyPlayer(Board &gameBoard, int id) : currentBoard(gameBoard) {
    playerId = id;
}


void greedyPlayer::updateUI() {
    return;
}


void greedyPlayer::makeFirstMove(int* move) {
    move[0] = rand() % 361;
}


void greedyPlayer::makeMoves(int* moves) {

    // priority queue to handle move decisions
    MPQ moveQueue;

    char pieceType;

    // for each potential board position
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            // skip if blank space
            if (currentBoard.isValidMove(i*19 + j)) { continue; }

            pieceType = currentBoard.getValue(i, j);

            // add the best move(s) to the queue
            pushBestMoves(pieceType, i * 19 + j, moveQueue);
        }
    }

    // if I cannot, see if opponent could win next round


    // if they cannot, make greedy two moves
}


void greedyPlayer::pushBestMoves(char pieceType, int pos, MPQ& moveQueue) {

    // go through posDiag, negDiag, horizontal, vertical
    // make array of best moves, depending on whether it is opponent or not

    int bestLength = 0;
    int numBest = 0;
    int bestMoves[50][2];

    // working Length;
    int wLength;

    // adjusts how far from original position we are
    int offset;

    // array of distances in one dimensional array of positions.
    // used to find neighbors quickly
    // 0 = horizontal, 1 = vertical, 2 = posDiag, 3 = negDiag
    int offsets[4] = {1, 19, 20, 18};
    char wPiece = pieceType;

    // for each possible direction (diagonals, vertical, horizontal)
    for (int i : offsets) {
        // initialize
        offset = 0;
        wPiece = pieceType;
        wLength = -1;

        // calculate distance back
        while (wPiece == pieceType) {
            wLength++;
            offset++;
            wPiece = currentBoard.getValueSingle(pos - offset * i);
        }

        // check if wPiece is empty, if it is, increment wLength and offset
        if (currentBoard.isValidMove(pos - offset * i)) {
            wLength++;
            
        }

        // reset values for next pass
        offset = 0;
        wPiece = pieceType

        // calculate distance forwards
        while (wPiece == pieceType) {
            wLength++;
            offset++;
            wPiece = currentBoard.getValueSingle(pos + offset * i);
        }
    }


























}
