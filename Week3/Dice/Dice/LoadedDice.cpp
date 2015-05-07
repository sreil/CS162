/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Loaded dice cpp file
*********************************************************************/
#include <iostream>
#include <cmath> //for random
#include "LoadedDice.h"

LoadedDice::LoadedDice() : Dice() //constructor
{
}

LoadedDice::LoadedDice(int sides) : Dice(sides)
{
}

int LoadedDice::rollDice()
{
	int rolled = (rand() % sides + 1);
	return rolled * 2;
}