/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: header file for dice program
*********************************************************************/

#ifndef DICE_H_INCLUDED
#define DICE_H_INCLUDED

class Dice
{
protected:
	int sides;

public:
	Dice();
	Dice(int);
	int rollDice();
};

#endif 