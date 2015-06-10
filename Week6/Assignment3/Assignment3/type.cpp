/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: character types
*********************************************************************/

#include "type.h"
#include "Dice.h"
#include <ctime>
#include <iostream>
#include <string>
#include <time.h>

int Character::defend() //calculates how much defense character receives
{
	Dice* dice = new Dice(diceD, sidesD);
	return dice->rollDice();
}

string Character::getName() //to get name of character
{
	return name;
}

int Character::getArmor() //to get the armor of character
{
	return armor;
}

int Character::getStrength() //to get strength of character
{
	return strengthPoints;
}

void Character::setStrength(int strengthP) //set strength of character
{
	strengthPoints = strengthP;
}

string Character::getClassType() //get the class type
{
	return classType;
}

void Character::setAchilles(bool broke) //set achilles, later used to see if broken or not
{
	achilles = broke;
}

bool Character::getAchilles() //get achilles value
{
	return achilles;
}

int Character::attack() //calculates how much the character attacks
{
	Dice * dice = new Dice(diceAttack, sidesAttack);
	return dice->rollDice();
}

Goblin::Goblin() //constructor
{
	name = "";
	classType = "Goblin";
	armor = 3;
	strengthPoints = 8;
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	const bool achilles = false;
}

Goblin::Goblin(string barName)
{
	name = barName;
	classType = "Goblin";
	armor = 3;
	strengthPoints = 8;
	diceD = 2;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	const bool achilles = false;
}

int Goblin::attack()
{
	int result = 0;

	Dice * aDice = new Dice(diceAttack, sidesAttack);
	result = aDice->rollDice();

	if (result == 12)
	{
		cout << " " << endl; //for easier readability
		cout << "Oh no!  The achilles was cut" << endl;
	}

	return result;
}

Barbarian::Barbarian() //constructor
{
	name = "";
	classType = "Barbarian";
	armor = 0;
	strengthPoints = 12;
	diceD = 2;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	bool achilles = false;

}

Barbarian::Barbarian(string barName)
{
	name = barName;
	classType = "Barbarian";
	armor = 0;
	strengthPoints = 12;
	diceD = 2;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	bool achilles = false;
}


Reptile::Reptile() //constructor
{
	name = "";
	classType = "Reptile";
	armor = 7;
	strengthPoints = 18;
	diceD = 1;
	sidesD = 6;
	diceAttack = 3;
	sidesAttack = 6;
	bool achilles = false;
}

Reptile::Reptile(string barName)
{
	name = barName;
	classType = "Reptile";
	armor = 7;
	strengthPoints = 18;
	diceD = 1;
	sidesD = 6;
	diceAttack = 3;
	sidesAttack = 6;
	bool achilles = false;
}


BlueMen::BlueMen() //constructor
{
	name = "";
	classType = "BlueMen";
	armor = 3;
	strengthPoints = 12;
	diceD = 3;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	bool achilles = false;
}

BlueMen::BlueMen(string barName)
{
	name = barName;
	classType = "BlueMen";
	armor = 7;
	strengthPoints = 12;
	diceD = 3;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	bool achilles = false;
}

Shadow::Shadow() //constructor
{
	name = "";
	classType = "Shadow";
	armor = 0;
	strengthPoints = 12;
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	bool achilles = false;
}

Shadow::Shadow(string barName) 
{
	name = barName;
	classType = "Shadow";
	armor = 0;
	strengthPoints = 12;
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	bool achilles = false;
}

int Shadow::defend() //calculates defense
{
	int result = 0;
	Dice* dodge = new Dice(1, 2);
	result = dodge->rollDice();

	if (result == 1)
	{
		cout << " " << endl; //for easier readability
		cout << "WOW! The Shadow dodged the attack " << endl;
		return 100; 
	}
	else
	{
		Dice* dice = new Dice(diceD, sidesD);
		return dice->rollDice();
	}
}