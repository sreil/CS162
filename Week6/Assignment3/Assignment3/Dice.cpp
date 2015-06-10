/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: dice class
*********************************************************************/

#include "Dice.h"
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;

Dice::Dice()
{
	numDice = 1;
	numFaces = 2;
}

Dice::Dice(int dice, int face)
{
	setDice(dice);
	setFaces(face);
}

void Dice::setDice(int dice)
{
	numDice = dice;
}

void Dice::setFaces(int sides)
{
	numFaces = sides;
}

int Dice::rollDice()
{
	srand(time(NULL));
	int total = 0;
	for (int i = 0; i < numDice; i++)
	{
		total += rand() % numFaces + 1;
	}

	return total;

}