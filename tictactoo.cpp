#include <time.h>
#include <iostream>


using namespace std;


int main()
{
	
	//State explained: Decides what loop to go through; 1 is setup, 2 is title, 3 is player move, 4 is opponent move, 5 is victory screen, 0 is game exited
	int state = 1, i, j, XorY=1,possMovesVal=9;
	const int BOARDSIZE = 5;
	char ans = 'n', gameBoard[BOARDSIZE][BOARDSIZE];
	string move, possMoves[] = { "TL","TM","TR","ML","M","MR","BL","BM","BR" };

	//Random Setup, for opponent movement, Irfen , Ill leave this opponent movement to you
	srand(time(NULL));

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

			state = 2;
		}

		//Title Screen
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

			//Press y at this part to clear screen and show board again, n to end game
			cout << "Play game?" << endl;
			cin >> ans;
			system("cls");
			if (ans != 'y' && ans != 'Y')
			{
				//If ans isnt Y or y, turn state to 0, which ends the game
				state = 0;
			}
			else
			{
				//If ans is y, set state to 3, which starts game
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

			

			//make your move
			cout << "Make your move: " << endl;
			cout << "(Possible moves are ";
			for (i = 0; i < possMovesVal; i++)
			{
				cout << possMoves[i];
				if (i < possMovesVal - 1)
				{
					cout << ", ";
				}
			}
			cout << ")" << endl;

			cin >> move;

			if (move == "TL" || move == "tl") {
				if(XorY%2==1)
				{
					if (gameBoard[0][0] == ' ') {
					gameBoard[0][0] = 'X'; 
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;  
					}
				}
				else {
					if (gameBoard[0][0] == ' ') {
						gameBoard[0][0] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				XorY++;
				
			}
			else if (move == "TM" || move == "tm") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[0][2] == ' ') {
						gameBoard[0][2] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[0][2] == ' ') {
						gameBoard[0][2] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "TR" || move == "tr") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[0][4] == ' ') {
						gameBoard[0][4] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[0][4] == ' ') {
						gameBoard[0][4] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "ML" || move == "ml") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][0] == ' ') {
						gameBoard[2][0] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][0] == ' ') {
						gameBoard[2][0] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "M" || move == "m") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][2] == ' ') {
						gameBoard[2][2] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][2] == ' ') {
						gameBoard[2][2] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "MR" || move == "mr") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[2][4] == ' ') {
						gameBoard[2][4] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[2][4] == ' ') {
						gameBoard[2][4] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BL" || move == "bl") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][0] == ' ') {
						gameBoard[4][0] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][0] == ' ') {
						gameBoard[4][0] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BM" || move == "bm") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][2] == ' ') {
						gameBoard[4][2] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][2] == ' ') {
						gameBoard[4][2] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}XorY++;
			}
			else if (move == "BR" || move == "br") {
				if (XorY % 2 == 1)
				{
					if (gameBoard[4][4] == ' ') {
						gameBoard[4][4] = 'X';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				else {
					if (gameBoard[4][4] == ' ') {
						gameBoard[4][4] = 'O';
					}
					else {
						system("cls");
						cout << "Cell already occupied!" << endl;
						continue;
					}
				}
				XorY++;
			}
			else {
				system("cls");
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
