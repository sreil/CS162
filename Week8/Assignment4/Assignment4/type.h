/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: header for the type class
*********************************************************************/

#ifndef TYPE_H
#define TYPE_H

#include <string>

using namespace std;

class type
{
public:
	type();
	void fight(type* attacker, type* defender);
	void strengthAdd();
	virtual void addPoints(type* target) = 0;
	int attackDice();
	int attackSides();
	int defenseDice();
	int defenseSides();
	int showArmor();
	int showMaxStrength();
	int showStrength();
	int showPoints();
	string showType();
	string showName();
	string showTeam();
	bool showIsGoblin();
	bool isAlive();
	void setAttackSides(int value);
	void setName(string inputName);

protected:
	virtual int attack(type* target);
	virtual int defense();
	int diceD;
	int sidesD;
	int diceAttack;
	int sidesAttack;
	int armor;
	int maxStrength;
	int strength;
	int health;
	bool isGoblin;
	string classType;
	string name;
	int points;
	string teamName;
};

class Goblin : public type
{
public:
	Goblin();
	Goblin(string input, string team);
private:
	virtual int attack(type* target);
	virtual void addPoints(type* target);

};

class Barbarian : public type
{
public:
	Barbarian();
	Barbarian(string input, string team);
	virtual void addPoints(type* target);
};

class Reptile : public type
{
public:
	Reptile();
	Reptile(string input, string team);
	virtual void addPoints(type* target);
};

class BlueMen : public type
{
public:
	BlueMen();
	BlueMen(string input, string team);
	virtual void addPoints(type* target);
};

class Shadow : public type
{
public:
	Shadow();
	Shadow(string input, string team);
private:
	virtual int defense();
	virtual void addPoints(type* target);
};

#endif