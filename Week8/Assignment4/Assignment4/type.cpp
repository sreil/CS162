/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: type class 
*********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include "type.h"

using namespace std;


type::type() //default constructor
{
}

int type::attack(type* target)
{
	int attackSum = 0;
	for (int i = 0; i < diceAttack; i++)
	{
		attackSum += rand() % sidesAttack + 1;
	}
	return attackSum;
}

int type::defense()
{
	int defenseSum = 0;
	for (int i = 0; i < diceD; i++)
	{
		defenseSum += rand() % sidesD + 1;
	}
	return defenseSum;
}

void type::fight(type* attacker, type* defender)
{
	// show defense strength at beginning of round
	cout << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << " has " << defender->showStrength() << " strength." << endl;

	cout << attacker->showTeam() << "'s " << attacker->showName() << " the " << attacker->showType() << " attacks " << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << endl;

	int attackRoll = attacker->attack(defender);
	int defenseRoll = defender->defense();

	cout << attacker->showTeam() << "'s " << attacker->showName() << " the " << attacker->showType() << " rolls an attack of " << attackRoll << ", and" << endl << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType();

	if (defenseRoll == 0 && defender->showType() == "Shadow")
	{
		cout << " successfully dodges the attack!" << endl;
	}
	else if (attackRoll == 12 && attacker->showType() == "Goblin"
		&& defender->showType() != "Goblin")
	{
		cout << "'s defense is useless against the Achilles strike!"
			<< endl;
	}
	else
	{
		cout << " rolls a defense of " << defenseRoll << " and has "
			<< defender->armor << " armor." << endl;
	}

	if (defenseRoll == 0 && defender->showType() == "Shadow")
	{
		cout << "No damage is dealt to " << defender->showTeam()
			<< "'s " << defender->showName() << " the Shadow!" << endl;
	}
	else if (attackRoll == 12 && attacker->showType() == "Goblin"
		&& defender->showType() != "Goblin")
	{
		if (defender->armor >= attackRoll)
		{
			cout << "The " << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << " armor blocks the achilles attack" << endl;
		}
		else
		{
			cout << attacker->showTeam() << "'s " << attacker->showName() << " the " << attacker->showType() << " deals " << attackRoll - defender->armor << " damage to " << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << endl;
			defender->strength -= (attackRoll - defender->armor);
		}
	}
	else if ((defenseRoll + defender->armor) >= attackRoll)
	{
		cout << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << "'s armor block the attack" << endl;
	}
	else
	{
		cout << attacker->showTeam() << "'s " << attacker->showName() << " the " << attacker->showType() << " deals " << attackRoll - defenseRoll - defender->armor << " damage to " << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << endl;
		defender->strength -= (attackRoll - defenseRoll
			- defender->armor);
	}

	if (defender->showStrength() < 0) //no negative strength allowed
	{
		defender->strength = 0;
	}

	cout << defender->showTeam() << "'s " << defender->showName() << " the " << defender->showType() << "'s strength is now " << defender->showStrength() << "." << endl;
}

void type::strengthAdd()
{
	int missing, healthRegen;
	missing = this->maxStrength - this->strength;
	cout << this->teamName << "'s " << this->name << " the " << this->classType << " is missing " << missing << " strength!" << endl;
	if (missing == 0)
	{
		cout << this->teamName << "'s " << this->name << " the " << this->classType
			<< " is at full strength, at " << this->strength << "." << endl;
		return;
	}
	healthRegen = rand() % 4;
	if (healthRegen == 0)
	{
		cout << this->teamName << "'s " << this->name << " the " << this->classType << " luckily regains all of its missing strength!" << endl;
		strength += missing;
		cout << this->teamName << "'s " << this->name << " the " << this->classType
			<< " now has " << this->strength << " strength." << endl;
	}
	else
	{
		cout << this->teamName << "'s " << this->name << " the " << this->classType << " regains half of its missing strength." << endl;
		
		strength += missing / 2;

		cout << this->teamName << "'s " << this->name << " the " << this->classType << " now has " << this->strength << " strength." << endl;
	}
}

int type::attackDice()
{
	return this->diceAttack;
}

int type::attackSides()
{
	return this->sidesAttack;
}

int type::defenseDice()
{
	return this->diceD;
}

int type::defenseSides()
{
	return this->sidesD;
}

int type::showArmor()
{
	return this->armor;
}

int type::showMaxStrength()
{
	return this->maxStrength;
}

int type::showStrength()
{
	return this->strength;
}

int type::showPoints()
{
	return this->points;
}

string type::showType()
{
	return this->classType;
}

string type::showName()
{
	return this->name;
}

string type::showTeam()
{
	return this->teamName;
}

bool type::showIsGoblin()
{
	return isGoblin;
}

bool type::isAlive()
{
	if (strength > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void type::setAttackSides(int value)
{
	sidesAttack = value;
}
void type::setName(string input)
{
	this->name = input;
}

Goblin::Goblin() : type() //default constructor
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	armor = 3;
	maxStrength = 8;
	strength = 8;
	points = 0;
	isGoblin = true;
	classType = "Goblin";
	name = "";
}

Goblin::Goblin(string input, string team) : type()
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	armor = 3;
	maxStrength = 8;
	strength = 8;
	points = 0;
	isGoblin = true;
	classType = "Goblin";
	name = input;
	teamName = team;
}
int Goblin::attack(type* target)
{
	int attackSum = 0;
	for (int i = 0; i < diceAttack; i++)
	{
		attackSum += rand() % sidesAttack + 1;
	}
	if (attackSum == 12 && target->showIsGoblin() == false)
	{
		target->setAttackSides(target->attackSides() / 2);
		cout << "The goblin hit the Achilles of the "
			<< target->showType() << "!" << endl;
		cout << "The attack power of the " << target->showType() << " is now " << target->attackDice() << target->attackSides() << "!" << endl;
	}
	return attackSum;
}

void Goblin::addPoints(type* target) //calculates points to add
{
	if (target->showType() == "Goblin")
	{
		points += 3;
	}
	else if (target->showType() == "Barbarian")
	{
		points += 4;
	}
	else if (target->showType() == "Reptile Person")
	{
		points += 7;
	}
	else if (target->showType() == "Blue Man")
	{
		points += 10;
	}
	else if (target->showType() == "Shadow")
	{
		points += 8;
	}
}

Barbarian::Barbarian() : type() //default constructor
{
	diceD = 2;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	armor = 0;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Barbarian";
}

Barbarian::Barbarian(string input, string team) : type()
{
	diceD = 2;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 6;
	armor = 0;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Barbarian";
	name = input;
	teamName = team;
}

void Barbarian::addPoints(type* target)
{
	if (target->showType() == "Goblin")
	{
		points += 2;
	}
	else if (target->showType() == "Barbarian")
	{
		points += 3;
	}
	else if (target->showType() == "Reptile Person")
	{
		points += 6;
	}
	else if (target->showType() == "Blue Man")
	{
		points += 9;
	}
	else if (target->showType() == "Shadow")
	{
		points += 7;
	}
}

Reptile::Reptile() : type() //default constructor
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 3;
	sidesAttack = 6;
	armor = 7;
	maxStrength = 18;
	strength = 18;
	points = 0;
	isGoblin = false;
	classType = "Reptile Person";
}

Reptile::Reptile(string input, string team) : type()
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 3;
	sidesAttack = 6;
	armor = 7;
	maxStrength = 18;
	strength = 18;
	points = 0;
	isGoblin = false;
	classType = "Reptile Person";
	name = input;
	teamName = team;
}

void Reptile::addPoints(type* target)
{
	if (target->showType() == "Goblin")
	{
		points += 1;
	}
	else if (target->showType() == "Barbarian")
	{
		points += 2;
	}
	else if (target->showType() == "Reptile Person")
	{
		points += 3;
	}
	else if (target->showType() == "Blue Man")
	{
		points += 5;
	}
	else if (target->showType() == "Shadow")
	{
		points += 3;
	}
}

BlueMen::BlueMen() : type()
{
	diceD = 3;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	armor = 3;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Blue Man";
}

BlueMen::BlueMen(string input, string team) : type()
{
	diceD = 3;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	armor = 3;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Blue Man";
	name = input;
	teamName = team;
}

void BlueMen::addPoints(type* target)
{
	if (target->showType() == "Goblin")
	{
		points += 1;
	}
	else if (target->showType() == "Barbarian")
	{
		points += 1;
	}
	else if (target->showType() == "Reptile Person")
	{
		points += 2;
	}
	else if (target->showType() == "Blue Man")
	{
		points += 3;
	}
	else if (target->showType() == "Shadow")
	{
		points += 2;
	}
}


Shadow::Shadow() : type() //default constructor
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	armor = 0;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Shadow";
}

Shadow::Shadow(string input, string team) : type()
{
	diceD = 1;
	sidesD = 6;
	diceAttack = 2;
	sidesAttack = 10;
	armor = 0;
	maxStrength = 12;
	strength = 12;
	points = 0;
	isGoblin = false;
	classType = "Shadow";
	name = input;
	teamName = team;
}


int Shadow::defense()
{
	int dodge = rand() % 2;
	if (dodge == 1)
	{
		return 0;
	}
	else
	{
		int defenseSum = 0;
		for (int i = 0; i < diceD; i++)
		{
			defenseSum += rand() % sidesD + 1;
		}
		return defenseSum;
	}
}

void Shadow::addPoints(type* target)
{
	if (target->showType() == "Goblin")
	{
		points += 1;
	}
	else if (target->showType() == "Barbarian")
	{
		points += 2;
	}
	else if (target->showType() == "Reptile Person")
	{
		points += 3;
	}
	else if (target->showType() == "Blue Man")
	{
		points += 6;
	}
	else if (target->showType() == "Shadow")
	{
		points += 3;
	}
}