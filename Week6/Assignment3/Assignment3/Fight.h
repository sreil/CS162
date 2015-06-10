/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: header for battle sequence
*********************************************************************/

#include <vector>
#include "type.h"
#include <string>

using namespace std;

#ifndef ASSGN3_BATTLE_H
#define ASSGN3_BATTLE_H


class Fight {
private:
	vector<Character*> CharacterList;
public:
	//Battle();

	void addCharacter(Character*);
	void removeCharacter(string);
	void fight(Character*, Character*);
	Character* getCharacter(string);

};

#endif