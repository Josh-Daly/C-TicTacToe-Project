#include <time.h>
#include <iostream>

using namespace std;

void possMovesFunc(string*, int);
bool checkWinner(char gameBoard[5][5]);
bool isBoardFull(char gameBoard[5][5]);

int main()
{
    // State explained: Decides what loop to go through; 1 is setup, 2 is title, 3 is player move, 0 is game exited
    int state = 1, i, j, XorY = 1, possMovesVal = 9;
    const int BOARDSIZE = 5;
    char ans = 'n', gameBoard[BOARDSIZE][BOARDSIZE];
    string move;
    string possMoves[] = { "TL","TM","TR","ML","M","MR","BL","BM","BR" };
    string movesReplace[] = { "-TL-","-TM-","-TR-","-ML-","-M-","-MR-","-BL-","-BM-","-BR-" };

    while (state != 0)
    {
        // Loop to setup board, called at start and after reset, called by setting state to 1
        if (state == 1)
        {
            gameBoard[0][0] = ' ';
            gameBoard[0][1] = '|';
            gameBoard[0][2] = ' ';
            gameBoard[0][3] = '|';
            gameBoard[0][4] = ' ';
            // Above = []|[]|[]
            gameBoard[1][0] = '-';
            gameBoard[1][1] = '+';
            gameBoard[1][2] = '-';
            gameBoard[1][3] = '+';
            gameBoard[1][4] = '-';
            // Above = -+-+-
            gameBoard[2][0] = ' ';
            gameBoard[2][1] = '|';
            gameBoard[2][2] = ' ';
            gameBoard[2][3] = '|';
            gameBoard[2][4] = ' ';
            // Above = []|[]|[]
            gameBoard[3][0] = '-';
            gameBoard[3][1] = '+';
            gameBoard[3][2] = '-';
            gameBoard[3][3] = '+';
            gameBoard[3][4] = '-';
            // Above = -+-+-
            gameBoard[4][0] = ' ';
            gameBoard[4][1] = '|';
            gameBoard[4][2] = ' ';
            gameBoard[4][3] = '|';
            gameBoard[4][4] = ' ';
            // Above = []|[]|[]

            state = 2;
        }

        // Title Screen
        if (state == 2)
        {
            cout << "Tic Tac Toe!" << endl;

            cout << "____ " << "___" << "  ___" << endl;
            cout << " / " << "  /" << "   /  " << endl;
            cout << "/  " << "_/_ " << " /___" << endl;

            cout << "____ " << "___" << "    ___" << endl;
            cout << " / " << " /  /| " << " /" << endl;
            cout << "/  " << "/__/ |" << " /___ " << endl;

            cout << "____ " << "___" << "  ___" << endl;
            cout << " / " << " /  /" << " /__/" << endl;
            cout << "/  " << "/__/ " << "/___" << endl;

            // Press y at this part to clear screen and show board again, n to end game
            cout << "Play game?" << endl;
            cin >> ans;
            system("cls");
            if (ans != 'y' && ans != 'Y')
            {
                // If ans isnt Y or y, turn state to 0, which ends the game
                state = 0;
            }
            else
            {
                // If ans is y, set state to 3, which starts game
                state = 3;
            }
        }

        // Loop for player move (Player 1: X, Player 2: O)
        if (state == 3)
        {
            // Print Board
            for (i = 0; i < BOARDSIZE; i++)
            {
                for (j = 0; j < BOARDSIZE; j++)
                {
                    cout << gameBoard[i][j];
                }
                cout << endl;
            }

            // Indicate which player's turn
            if (XorY % 2 == 1) {
                cout << "Player 1 (X) - Make your move" << endl;
            }
            else {
                cout << "Player 2 (O) - Make your move" << endl;
            }

            possMovesFunc(&possMoves[0], possMovesVal);
            cin >> move;

            bool validMove = false;
            char symbol = (XorY % 2 == 1) ? 'X' : 'O';

            if (move == "TL" || move == "tl") {
                if (gameBoard[0][0] == ' ') {
                    gameBoard[0][0] = symbol;
                    possMoves[0] = movesReplace[0];
                    validMove = true;
                }
            }
            else if (move == "TM" || move == "tm") {
                if (gameBoard[0][2] == ' ') {
                    gameBoard[0][2] = symbol;
                    possMoves[1] = movesReplace[1];
                    validMove = true;
                }
            }
            else if (move == "TR" || move == "tr") {
                if (gameBoard[0][4] == ' ') {
                    gameBoard[0][4] = symbol;
                    possMoves[2] = movesReplace[2];
                    validMove = true;
                }
            }
            else if (move == "ML" || move == "ml") {
                if (gameBoard[2][0] == ' ') {
                    gameBoard[2][0] = symbol;
                    possMoves[3] = movesReplace[3];
                    validMove = true;
                }
            }
            else if (move == "M" || move == "m") {
                if (gameBoard[2][2] == ' ') {
                    gameBoard[2][2] = symbol;
                    possMoves[4] = movesReplace[4];
                    validMove = true;
                }
            }
            else if (move == "MR" || move == "mr") {
                if (gameBoard[2][4] == ' ') {
                    gameBoard[2][4] = symbol;
                    possMoves[5] = movesReplace[5];
                    validMove = true;
                }
            }
            else if (move == "BL" || move == "bl") {
                if (gameBoard[4][0] == ' ') {
                    gameBoard[4][0] = symbol;
                    possMoves[6] = movesReplace[6];
                    validMove = true;
                }
            }
            else if (move == "BM" || move == "bm") {
                if (gameBoard[4][2] == ' ') {
                    gameBoard[4][2] = symbol;
                    possMoves[7] = movesReplace[7];
                    validMove = true;
                }
            }
            else if (move == "BR" || move == "br") {
                if (gameBoard[4][4] == ' ') {
                    gameBoard[4][4] = symbol;
                    possMoves[8] = movesReplace[8];
                    validMove = true;
                }
            }

            system("cls");
            if (!validMove) {
                cout << "Invalid or occupied move!" << endl;
                continue;
            }

            // Check for win or draw
            if (checkWinner(gameBoard)) {
                for (i = 0; i < BOARDSIZE; i++) {
                    for (j = 0; j < BOARDSIZE; j++) {
                        cout << gameBoard[i][j];
                    }
                    cout << endl;
                }
                if(XorY % 2 == 1) {
                    cout << "Player 1 WON!" << endl;
                }
                else {
                cout << "Player 2 WON!" << endl;
                }

                return 0;
            }
            if (isBoardFull(gameBoard)) {
                for (i = 0; i < BOARDSIZE; i++) {
                    for (j = 0; j < BOARDSIZE; j++) {
                        cout << gameBoard[i][j];
                    }
                    cout << endl;
                }
                cout << "It's a draw!" << endl;
                return 0;
            }

            XorY++; // Switch to next player
        }
    }

    // Clear screen command
    system("cls");
    cout << "Game ended." << endl;

    return 0;
}

void possMovesFunc(string* pM, int pMV)
{
    int iF;
    cout << "(";
    for (iF = 0; iF < pMV; iF++)
    {
        cout << *pM;
        if (iF < pMV - 1)
        {
            cout << ", ";
        }
        *pM++;
    }
    cout << ")" << endl;
}

bool isBoardFull(char gameBoard[5][5]) {
    int playableCells[9][2] = {
        {0,0}, {0,2}, {0,4},
        {2,0}, {2,2}, {2,4},
        {4,0}, {4,2}, {4,4}
    };
    for (int i = 0; i < 9; i++) {
        if (gameBoard[playableCells[i][0]][playableCells[i][1]] == ' ') {
            return false;
        }
    }
    return true;
}

bool checkWinner(char gameBoard[5][5]) {
    // Check rows
    for (int i = 0; i < 5; i += 2) {
        if (gameBoard[i][0] == gameBoard[i][2] && gameBoard[i][2] == gameBoard[i][4] && gameBoard[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 5; i += 2) {
        if (gameBoard[0][i] == gameBoard[2][i] && gameBoard[2][i] == gameBoard[4][i] && gameBoard[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if (gameBoard[0][0] == gameBoard[2][2] && gameBoard[2][2] == gameBoard[4][4] && gameBoard[0][0] != ' ') {
        return true;
    }
    if (gameBoard[0][4] == gameBoard[2][2] && gameBoard[2][2] == gameBoard[4][0] && gameBoard[0][4] != ' ') {
        return true;
    }

    return false;
}