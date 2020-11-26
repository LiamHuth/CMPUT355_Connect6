#pragma once
#include "Player.h"
#include "Board.h"
#include <queue>
#include <vector>


struct moveWrapper {
	int priority;
	int move1;
	int move2;
	bool twoMoves;

	bool operator<(const moveWrapper& rhs) const
	{
		return priority < rhs.priority;
	}

	bool operator==(const moveWrapper& rhs) const
	{
		// check if same number of moves stored
		if (twoMoves != rhs.twoMoves) { return false; }

		// if only one move stored, only one comparison needed
		if (!twoMoves) { return move1 == rhs.move1; }

		// otherwise need to do more comparisons
		if (move1 == rhs.move1 && move2 == rhs.move2) { return true; }
		if (move1 == rhs.move2 && move2 == rhs.move1) { return true; }

		return false;
	}
};

using MPQ = std::priority_queue<moveWrapper>;

class greedyPlayer : public Player {
public:

    greedyPlayer(Board &gameBoard, int id);

    void makeFirstMove(int* move);

    void makeMoves(int* moves);

    void updateUI();

private:

    void pushBestMoves(char pieceType, int pos, MPQ& moveQueue);

    Board& currentBoard;
};
