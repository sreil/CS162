/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Create a Dice class that simulates rolling a die with a different number of sides.
*********************************************************************/

#include <iostream>
#include <cmath> //for random
#include <ctime>
#include "Dice.h"

Dice::Dice()
{
	sides = 6;
}

Dice::Dice(int numSides)
{
	sides = numSides;
}

int Dice::rollDice()
{
	int rollResult;

	srand(time(0));

	rollResult = rand() % sides + 1;
	return rollResult;
}