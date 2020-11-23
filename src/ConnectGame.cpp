#include "ConnectGame.h"

ConnectGame::ConnectGame() {

    // allow stdin to write directly to program, avoid terminal buffer
    struct termios newterminal;
    tcgetattr(STDIN_FILENO, &oldterminal);
    newterminal = oldterminal;
    newterminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newterminal);

    gameOn = true;
}


ConnectGame::~ConnectGame() {
    // restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldterminal);
}


bool ConnectGame::isGameOn() {
        return gameOn;
}


void ConnectGame::start() {
    // for UI
    char input = 0;
    int exitCursor = 0;
    int playerChoiceCursor = 0;
    int playerChoices[2] = {-1, -1};
    int numTypesPlayers = 2;

    // get info on what type of players are involved
    char options[2][10] = {"Human", "Random"};

    // player choice UI
    while (playerChoices[1] == -1) {
        system("clear");
        printf("\033[1mPlayer %d:\033[0m\n", (playerChoices[0] == -1 ? 1 : 2));
        for (int i = 0; i < numTypesPlayers; i++) {
            printf("%s%s\n", (playerChoiceCursor == i ? "> " : "  "), options[i]);
        }

        // get input
        input = getInput();

        // handle tab
        if (input == '\t') {
            if (playerChoiceCursor == (numTypesPlayers-1)) { playerChoiceCursor = 0; }
            else { playerChoiceCursor++; }
        }

        // handle enter
        if (input == '\n') {
            if (playerChoices[0] == -1) {
                playerChoices[0] = playerChoiceCursor;
                playerChoiceCursor = 0;
            } else {
                playerChoices[1] = playerChoiceCursor;
            }
        }
    }

    // initialize players
    Player* Players[2] = { nullptr };
    for (int i = 0; i < 2; i++) {
        switch (playerChoices[i]) {
            // human
            case 0:
                Players[i] = new userPlayer(boardState, i);
                break;
            // random
            case 1:
                Players[i] = new randomPlayer(boardState, i);
                break;
        }
    }

    int turn = 0;
    int* moves = new int[2];

    // do first move
    Players[turn]->makeFirstMove(moves);
    boardState.setValue(moves, (turn ? '1' : '0'), 1);

    // main loop
    do {
        // alternate player turn
        turn = (turn + 1) % 2;

        // get player decision
        Players[turn]->makeMoves(moves);

        // update board
        boardState.setValue(moves, (turn ? '1' : '0'), 2);

    } while (!boardState.decided());

    // Game over UI
    input = 0;
    while (input != '\n') {
        // refresh screen
        system("clear");
        boardState.printBoard(-1, -1, -1);
        printf("\n\033[1;%smPlayer %d Wins!\033[0m\n", (turn ? "97" : "36"), turn+1);

        // print options
        printf("%sPlay Again\n", (exitCursor ? "  " : "> "));
        printf("%sExit\n", (exitCursor ? "> " : "  "));

        // get input
        input = getInput();

        // handle tab
        if (input == '\t') { exitCursor = (exitCursor + 1) % 2; }
    }

    // exit
    if (exitCursor == 1) {
        gameOn = false;
        system("clear");
    }
    // new game
    else { boardState.reset(); }

    delete Players[0];
    delete Players[1];
    delete[] moves;
}
