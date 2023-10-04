#include <iostream>
#include <array>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void determineFirstTurn();
void turnO();
void turnX();
void determineXWin();
void determineOWin();
void determineTie();
void reloadBoard();

bool gameOver = false;

array <int, 2> placement{};
string xPlacement = " X";
string oPlacement = " O";
string board[5][5]{
		{"  "," |","  "," |","  "},
		{" -"," -"," -"," -"," -"},
		{"  "," |","  "," |","  "},
		{" -"," -"," -"," -"," -"},
		{"  "," |","  "," |","  "}
};

int main()
{
	if (gameOver != true)
	{
		//spaces that can be filled {0,0},{0,2},{0,4},{2,0},{2,2},{2,4},{4,0},{4,2},{4,4}

		// use to print the board out
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << "Who starts is decided by a coinflip: Heads will be O's, Tails will be X's" << endl;
		determineFirstTurn();
	}
	return 0;
}
void turnO()
{
	if (gameOver == true)
	{
		main();
	}
	else
	{
		cout << "it is now O's turn" << endl;
		cout << "Please enter the row number (1, 2, 3)" << endl;
		cin >> placement[0];
		cout << "Please enter the column number (1, 2, 3)" << endl;
		cin >> placement[1];

		if (placement[0] < 1 || placement[0] > 3)
		{
			cout << "this is not a valid option please try again" << endl;
			turnO();
		}
		else if (placement[1] < 1 || placement[1] > 3) {
			cout << "this is not a valid option please try again" << endl;
			turnO();
		}
		else
		{
			if (placement[0] == 1)
			{
				placement[0] = 0;
			}
			else if (placement[0] == 2)
			{
				placement[0] = 2;
			}
			else if (placement[0] == 3)
			{
				placement[0] = 4;
			}

			if (placement[1] == 1)
			{
				placement[1] = 0;
			}
			else if (placement[1] == 2)
			{
				placement[1] = 2;
			}
			else if (placement[1] == 3)
			{
				placement[1] = 4;
			}
		}
		if (board[placement[0]][placement[1]] == xPlacement || board[placement[0]][placement[1]] == oPlacement)
		{
			cout << "this is not a valid option please try again" << endl;
			turnO();
		}
		else {
			board[placement[0]][placement[1]] = oPlacement;
			reloadBoard();
			determineOWin();
		}
	}
}
void turnX()
{
	if (gameOver == true)
	{
		main();
	}
	else
	{
		cout << "it is now X's turn" << endl;
		cout << "Please enter the row number (1, 2, 3)" << endl;
		cin >> placement[0];
		cout << "Please enter the column number (1, 2, 3)" << endl;
		cin >> placement[1];

		if (placement[0] < 1 || placement[0] > 3)
		{
			cout << "this is not a valid option please try again" << endl;
			turnX();
		}
		else if (placement[1] < 1 || placement[1] > 3) {
			cout << "this is not a valid option please try again" << endl;
			turnX();
		}
		else
		{
			if (placement[0] == 1)
			{
				placement[0] = 0;
			}
			else if (placement[0] == 2)
			{
				placement[0] = 2;
			}
			else if (placement[0] == 3)
			{
				placement[0] = 4;
			}

			if (placement[1] == 1)
			{
				placement[1] = 0;
			}
			else if (placement[1] == 2)
			{
				placement[1] = 2;
			}
			else if (placement[1] == 3)
			{
				placement[1] = 4;
			}
		}
		if (board[placement[0]][placement[1]] == xPlacement || board[placement[0]][placement[1]] == oPlacement)
		{
			cout << "this is not a valid option please try again" << endl;
			turnX();
		}
		else {
			board[placement[0]][placement[1]] = xPlacement;
			reloadBoard();
			determineXWin();
		}
	}
}
void reloadBoard()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void determineFirstTurn()
{
	//use random to determine first turn
	srand(time(nullptr));
	int randomNum = rand() % 100 + 1;
	if (randomNum >= 50)
	{
		cout << "X plays first!" << endl;
		turnX();
	}
	else
	{
		cout << "O plays first!" << endl;
		turnO();
	}
}

void determineOWin()
{
	//there are 8 ways a person can win in tic tac toe
	if (oPlacement == board[0][0] && 
		oPlacement == board[0][2] && 
		oPlacement == board[0][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[2][0] && 
		oPlacement == board[2][2] && 
		oPlacement == board[2][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[4][0] && 
		oPlacement == board[4][2] && 
		oPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[0][0] && 
		oPlacement == board[2][0] && 
		oPlacement == board[4][0])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[0][2] && 
		oPlacement == board[2][2] && 
		oPlacement == board[4][2])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[0][4] && 
		oPlacement == board[2][4] && 
		oPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[0][0] && 
		oPlacement == board[2][2] && 
		oPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else if (oPlacement == board[4][0] && 
		oPlacement == board[2][2] && 
		oPlacement == board[0][4])
	{
		cout << "Tic-Tac-Toe O wins!" << endl;
		gameOver = true;
	}
	else
	{
		determineTie();
		turnX();
	}
}

void determineXWin() 
{
	//there are 8 ways a person can win in tic tac toe
	if (xPlacement == board[0][0] && 
		xPlacement == board[0][2] && 
		xPlacement == board[0][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[2][0] && 
		xPlacement == board[2][2] && 
		xPlacement == board[2][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[4][0] && 
		xPlacement == board[4][2] && 
		xPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[0][0] && 
		xPlacement == board[2][0] && 
		xPlacement == board[4][0])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[0][2] && 
		xPlacement == board[2][2] && 
		xPlacement == board[4][2])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[0][4] && 
		xPlacement == board[2][4] && 
		xPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[0][0] && 
		xPlacement == board[2][2] && 
		xPlacement == board[4][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else if (xPlacement == board[4][0] && 
		xPlacement == board[2][2] && 
		xPlacement == board[0][4])
	{
		cout << "Tic-Tac-Toe X wins!" << endl;
		gameOver = true;
	}
	else
	{
		determineTie();
		turnO();
	}
}
void determineTie()
{
	if ((xPlacement == board[0][0] || oPlacement == board[0][0]) &&
		(xPlacement == board[0][2] || oPlacement == board[0][2]) &&
		(xPlacement == board[0][4] || oPlacement == board[0][4]))
	{
		if ((xPlacement == board[2][0] || oPlacement == board[2][0]) &&
			(xPlacement == board[2][2] || oPlacement == board[2][2]) &&
			(xPlacement == board[2][4] || oPlacement == board[2][4]))
		{
			if ((xPlacement == board[4][0] || oPlacement == board[4][0]) &&
				(xPlacement == board[4][2] || oPlacement == board[4][2]) &&
				(xPlacement == board[4][4] || oPlacement == board[4][4]))
			{
				gameOver = true;
				cout << "whoops a tie!" << endl;
				main();
			}
		}
	}
}
