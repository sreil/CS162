/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Header for loaded dice
*********************************************************************/
#include "Dice.h"

#ifndef LOADEDDICE_H_INCLUDED
#define LOADEDDICE_H_INCLUDED

class LoadedDice : public Dice 
{
public:
	LoadedDice(); //constructor
	LoadedDice(int sides);
	int rollDice();
};

#endif