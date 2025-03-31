#include <iostream>
#include <stdlib.h> 

using namespace std;


int main()
{
	int state = 1, i, j;
	//State: 1 is setup, 2 is showing, 3 is player move, 4 is enemy move, 0 is game exited
	char ans = 'n';
	const int BOARDSIZE = 5;
	char gameBoard[BOARDSIZE][BOARDSIZE];
	string possMoves[] = { "TL","TM","TR","ML","M","MR","BL","BM","BR" };
	int possMovesVal = 9;
	string move;
	int XorY = 1;


	

	while (state != 0)
	{

		//Loop to setup board, called at start and after reset, called by setting state to 1
		if (state == 1)
		{
			gameBoard[0][0] = ' ';
			gameBoard[0][1] = '|';
			gameBoard[0][2] = ' ';
			gameBoard[0][3] = '|';
			gameBoard[0][4] = ' ';
			// Above = [] | [] | []
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

			state = 3;
		}

		//Loop to show game board, used if player enters wrong move
		if (state == 2)
		{
			//Print Board
			for (i = 0; i < BOARDSIZE; i++)
			{
				for (j = 0; j < BOARDSIZE; j++)
				{
					cout << gameBoard[i][j];
				}
				cout << endl;
			}

			//Loop to check for victory conditions
			for (i = 0; i < BOARDSIZE; i++)
			{

			}

			cout << "Possible moves: (";
			for (i = 0; i < possMovesVal; i++)
			{
				cout << possMoves[i];
				if (i < possMovesVal - 1)
				{
					cout << ", ";
				}
			}
			cout << ")" << endl;


			//Press y at this part to clear screen and show board again, n to end game
			cout << "Resume?" << endl;
			cin >> ans;
			system("cls");
			if (ans != 'y' && ans != 'Y')
			{
				//If ans isnt Y or y, turn state to 0, which ends the game
				state = 0;
			}
			else
			{
				//If ans is y, set state to 3, which allows to make a move
				state = 3;
			}

		}

		//Loop to let player move
		if (state == 3)
		{
			

			//Print Board
			for (i = 0; i < BOARDSIZE; i++)
			{
				for (j = 0; j < BOARDSIZE; j++)
				{
					cout << gameBoard[i][j];
				}
				cout << endl;
			}

			//Loop to check for victory conditions
			for (i = 0; i < BOARDSIZE; i++)
			{

			}

			cout << "Possible moves: (";
			for (i = 0; i < possMovesVal; i++)
			{
				cout << possMoves[i];
				if (i < possMovesVal - 1)
				{
					cout << ", ";
				}
			}
			cout << ")" << endl;

			//make your move
			cout << "Make your move (TL, TM, TR, ML, M, MR, BL, BM, BR): " << endl;
			cin >> move;



			

			if (move == "TL") {
				if(XorY%2==1)
				{
					if (gameBoard[0][0] == ' ') {
					gameBoard[0][0] = 'X'; 
					}
					else {
					cout << "Cell already occupied!" << endl;
					continue;  
					}
				}
				else {
					if (gameBoard[0][0] == ' ') {
						gameBoard[0][0] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				XorY++;
				
			}
			else if (move == "TM") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[0][2] == ' ') {
						gameBoard[0][2] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[0][2] == ' ') {
						gameBoard[0][2] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "TR") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[0][4] == ' ') {
						gameBoard[0][4] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[0][4] == ' ') {
						gameBoard[0][4] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "ML") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][0] == ' ') {
						gameBoard[2][0] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][0] == ' ') {
						gameBoard[2][0] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "M") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][2] == ' ') {
						gameBoard[2][2] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][2] == ' ') {
						gameBoard[2][2] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "MR") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][4] == ' ') {
						gameBoard[2][4] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][4] == ' ') {
						gameBoard[2][4] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BL") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][0] == ' ') {
						gameBoard[4][0] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][0] == ' ') {
						gameBoard[4][0] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BM") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][2] == ' ') {
						gameBoard[4][2] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][2] == ' ') {
						gameBoard[4][2] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BR") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][4] == ' ') {
						gameBoard[4][4] = 'X';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][4] == ' ') {
						gameBoard[4][4] = 'O';
					}
					else {
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				XorY++;
			}
			else {
				cout << "Invalid move!" << endl;
				continue;  
			}


			

		}


		system("cls");
	}

	//clear screen command
	system("cls");
	cout << "Game ended." << endl;

	return 0;
}


