/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Conway's Game of Life - menu options
*********************************************************************/

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board() //Constructor
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			board[i][j] = 46;
		};
	}

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			tempBoard[i][j] = 46;
		};
	}
}

void Board::print() //print board
{
	for (int i = 5; i < 45; i++)
	{
		for (int j = 5; j < 25; j++)
		{
			cout << board[i][j];
		}
		cout << " " << endl;
	}
}

void Board::temporary() //temp board
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << tempBoard[i][j];
		}
		cout << " " << endl;
	}
}

void Board::temporaryConvert() //converts temp board to real board
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			board[i][j] = tempBoard[i][j];
		}
	}
}

void Board::input() //user input
{
	char point = 'y';
	int x, y;
	while ((point == 'y') || (point == 'Y'))
	{
		cout << "Grid is 40x20" << endl;
		cout << "Enter X Coord :" << endl;
		cin >> x;
		cout << "Enter Y Coord :" << endl;
		cin >> y;

		board[y + 5][x + 5] = 88;

		cout << "Would you like to add another point? Y|N ";
		cin >> point;
	}


}

void Board::glider()
{
	int x, y;
	char check;

	cout << "Would you like to place the glider your self? Y|N:";
	cin >> check;

	//User set where  they want the pattern
	if ((check == 'y') || (check == 'Y'))
	{
		cout << "Grid is 40x20 "<< endl;
		cout << "Enter X Coord :";
		cin >> x;
		cout << "Enter Y Coord :";
		cin >> y;
		board[y + 5][x + 5] = 88;
		board[y + 6][x + 6] = 88;
		board[y + 7][x + 4] = 88;
		board[y + 7][x + 5] = 88;
		board[y + 7][x + 6] = 88;
	}
	else
	{
		board[8][8] = 88;
		board[9][9] = 88;
		board[10][7] = 88;
		board[10][8] = 88;
		board[10][9] = 88;
	}

}

void Board::oscillator() //oscillator pattern
{
	int x, y;
	char check;

	cout << "Would you like to place the oscillator yourself? Y/N:";
	cin >> check;

	if ((check == 'y') || (check == 'Y'))
	{
		cout << "Grid is 40x20\n Place where you would like the upper right corner of the pattern" << endl;
		cout << "Enter X Coord :";
		cin >> x;
		cout << "Enter Y Coord :";
		cin >> y;

		board[y + 5][x + 5] = 88;
		board[y + 5][x + 6] = 88;
		board[y + 5][x + 7] = 88;
	}
	else
	{
		board[8][8] = 88;
		board[8][9] = 88;
		board[8][10] = 88;
	}

}

void Board::gliderGun() //glider gun pattern
{
	int x, y;
	char check;

	cout << "Would you like to place the glider gun pattern yourself? Y/N:";
	cin >> check;

	if ((check == 'y') || (check == 'Y'))
	{
		cout << "Grid is 40x20 \n Place where you would like the upper right corner of the pattern" << endl;
		cout << "Enter X Coord :";
		cin >> x;
		cout << "Enter Y Coord :";
		cin >> y;

	
		board[y + 5][x + 7] = 88;
		board[y + 5][x + 8] = 88;
		board[y + 6][x + 7] = 88;
		board[y + 6][x + 8] = 88;

		board[y + 16][x + 5] = 88;
		board[y + 16][x + 6] = 88;

		board[y + 16][x + 10] = 88;
		board[y + 16][x + 11] = 88;

		board[y + 18][x + 6] = 88;
		board[y + 18][x + 10] = 88;

		board[y + 19][x + 7] = 88;
		board[y + 19][x + 8] = 88;
		board[y + 19][x + 9] = 88;

		board[y + 20][x + 7] = 88;
		board[y + 20][x + 8] = 88;
		board[y + 20][x + 9] = 88;

		board[y + 23][x + 10] = 88;

		board[y + 24][x + 9] = 88;
		board[y + 24][x + 10] = 88;
		board[y + 24][x + 11] = 88;

		board[y + 25][x + 8] = 88;
		board[y + 25][x + 12] = 88;

		board[y + 26][x + 10] = 88;

		board[y + 27][x + 7] = 88;
		board[y + 27][x + 13] = 88;

		board[y + 28][x + 7] = 88;
		board[y + 28][x + 13] = 88;

		board[y + 29][x + 8] = 88;
		board[y + 29][x + 12] = 88;

		board[y + 30][x + 9] = 88;
		board[y + 30][x + 10] = 88;
		board[y + 30][x + 11] = 88;

		board[y + 39][x + 9] = 88;
		board[y + 39][x + 10] = 88;
		board[y + 40][x + 9] = 88;
		board[y + 40][x + 10] = 88;
	}
	else
	{
		board[7][14] = 88;
		board[7][15] = 88;
		board[8][14] = 88;
		board[8][15] = 88;

		board[18][12] = 88;
		board[18][13] = 88;

		board[18][17] = 88;
		board[18][18] = 88;

		board[20][13] = 88;
		board[20][17] = 88;

		board[21][14] = 88;
		board[21][15] = 88;
		board[21][16] = 88;

		board[22][14] = 88;
		board[22][15] = 88;
		board[22][16] = 88;

		board[25][17] = 88;

		board[26][16] = 88;
		board[26][17] = 88;
		board[26][18] = 88;

		board[27][15] = 88;
		board[27][19] = 88;

		board[28][17] = 88;

		board[29][14] = 88;
		board[29][20] = 88;

		board[30][14] = 88;
		board[30][20] = 88;

		board[31][15] = 88;
		board[31][19] = 88;

		board[32][16] = 88;
		board[32][17] = 88;
		board[32][18] = 88;

		board[41][16] = 88;
		board[41][17] = 88;
		board[42][16] = 88;
		board[42][17] = 88;
	}

}

void Board::runSim() //decides what cells are alive or dead
{
	int liveCells = 0;

	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j<50; j++)
		{
			liveCells = 0;
			if (board[i - 1][j - 1] == 88)
			{
				liveCells++;
			}
			if (board[i - 1][j] == 88)
			{
				liveCells++;
			}
			if (board[i - 1][j + 1] == 88)
			{
				liveCells++;
			}
			if (board[i][j - 1] == 88)
			{
				liveCells++;
			}
			if (board[i][j + 1] == 88)
			{
				liveCells++;
			}
			if (board[i + 1][j - 1] == 88)
			{
				liveCells++;
			}
			if (board[i + 1][j] == 88)
			{
				liveCells++;
			}
			if (board[i + 1][j + 1] == 88)
			{
				liveCells++;
			}

			if ((board[i][j] == 88) && ((liveCells < 2) || (liveCells > 3)))
			{
				tempBoard[i][j] = 46;
			}

			else if ((board[i][j] == 46) && ((liveCells == 3)))
			{
				tempBoard[i][j] = 88;
			}

			else if ((board[i][j] == 88) && ((liveCells == 2) || (liveCells == 3)))
			{
				tempBoard[i][j] = 88;
			}

			else
			{
				tempBoard[i][j] = 46;
			}

		}
	}
}