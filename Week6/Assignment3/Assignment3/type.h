/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: header for character types
*********************************************************************/

#include <string>
#include "Dice.h"

using namespace std;

#ifndef ASSGN3_CHARACTER_H
#define ASSGN3_CHARACTER_H


class Character
{
public:
	virtual int attack();
	virtual int defend();
	string getName();
	int getArmor();
	int getStrength();
	void setStrength(int);
	string getClassType();
	bool getAchilles();
	void setAchilles(bool);

protected:
	int armor;
	string classType;
	int diceD;
	int sidesD;
	int diceAttack;
	int sidesAttack;
	int strengthPoints;
	string name;
	bool achilles;
};

class Goblin : public Character
{
public:
	using Character::attack;
	using Character::defend;
	Goblin();
	Goblin(string);
	int attack();
};

class Barbarian : public Character
{
public:
	Barbarian();
	Barbarian(string);
};

class Reptile : public Character
{
public:
	Reptile();
	Reptile(string);
};

class BlueMen : public Character
{
public:
	BlueMen();
	BlueMen(string);
};

class Shadow : public Character
{
public:
	Shadow();
	Shadow(string);
	int defend();
};


#endif