/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: header for the dice roll aspect of the game
*********************************************************************/

#ifndef ASSGN3_DICE_H
#define ASSGN3_DICE_H

class Dice {

public:
	Dice();
	Dice(int, int);
	int rollDice();
	void setFaces(int);
	void setDice(int);

private:
	int numFaces;
	int numDice;

};


#endif