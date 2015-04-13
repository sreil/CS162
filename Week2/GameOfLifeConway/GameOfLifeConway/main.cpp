/*
Rules:
1. If an occupied cell has zero or one neighbor, it dies of loneliness.
2. If an occupied cell has more than three neighbors, it dies of overcrowding.
3. If an empty cell has exactly three occupied neighbor cells, there is a birth of a new cell
to replace the empty cell.
4. Births and deaths are instantaneous and occur at the changes of generation.

• programming style and documentation (10%)
• build the array/matrix providing a fixed simple oscillator (30%)
• the display allows the user to see the change(s) in the shape(s) (10%)
• allow the user to specify the starting location of the pattern (10%)
• add the glider pattern (5%)
• the glider should simply disappear off an edge (10%)
• add a glider gun or cannon pattern (5%)
• reflections document to include the design description, test plan, test results, and comments about
how you resolved problems during the assignment (20%)

/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162 
** Description: Conway's Game of Life - menu
*********************************************************************/

#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	int selection = 0;
	Board board; //create object

	while ((selection < 1) || (selection > 4)) //menu for different options
	{
		cout << "Conway's Game of Life Menu: " << endl;
		cout << " " << endl;
		cout << "Press 1 for the Oscillator pattern" << endl;
		cout << "Press 2 for the glider pattern" << endl;
		cout << "Press 3 for the glider gun pattern" << endl;
		cout << "Press 4 if you would like to input coordinates" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:
			board.oscillator();
			break;
		case 2:
			board.glider();
			break;
		case 3:
			board.gliderGun();
			break;
		case 4:
			board.input();
			break;
		default:	
			cout << "Please enter a number between 1- 4" << endl;
		}
	}
	
	while (true)
	{
		cout << "\n\n\n";
		cout << "Original Pattern" << endl;
		board.print();
		board.runSim();
		board.temporaryConvert();
		cout << "\n\n\n";
		cout << "New Pattern" << endl;
		board.print();
	}
	
	return 0;
}