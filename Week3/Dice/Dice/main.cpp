/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Create a Dice class that simulates rolling a die with a different number of sides.
*********************************************************************/

#include <iostream>
#include "LoadedDice.h"

using namespace std;

int main(){

	Dice dice1;
	Dice dice2;

	int roll1 = dice1.rollDice();
	int roll2 = dice2.rollDice();

	cout << "Your first roll you got a " << roll1 << " and your second roll was " << roll2 << endl;
	cout << "The total of both your rolls is " << roll1 + roll2 << endl;

	LoadedDice dice3;
	LoadedDice dice4;

	int roll3 = dice3.rollDice();
	int roll4 = dice4.rollDice();

	cout << "You also used the loaded dice and rolled a " << roll3 << " and then you rolled a " << roll4 << endl;

	return 0;
}