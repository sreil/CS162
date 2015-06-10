/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: menu for fantasy combat game
*********************************************************************/

#include <iostream>
#include "Dice.h"
#include "Fight.h"
#include "type.h"
#include <string>

using namespace std;

int main()
{
	Fight fight;

	char answer = 'n'; //used below for fighting
	int choice = 0; //for the menu selection
	string name = ""; //to name your character

	Character* attacker; //pointer to attacker
	Character* defender; //pointer to defender

	while (choice != 4) //menu begins
	{
		int character = 0; //for seclecting character
		cout << "Prepare to fight!" << endl;
		cout << "Press 1 to create a character" << endl;
		cout << "Press 2 to remove a character" << endl;
		cout << "Press 3 to fight" << endl;
		cout << "Press 4 to exit program" << endl;
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1: 
		{
			cout << "What would you like your character to be called?" << endl;
			getline(cin, name);
			cout << "Please pick the class you'd like to be " << endl;

			cout << "Press 1 to be a goblin" << endl;
			cout << "Press 2 to be a barbarian" << endl;
			cout << "Press 3 to be the reptile people" << endl;
			cout << "Press 4 to be the blue people" << endl;
			cout << "Press 5 to be the shadow" << endl;
			cout << " " << endl;
			cout << "Please enter your choice now ";
			cin >> character;

			switch (character) {
			case 1:
			{
				Goblin *newGoblin = new Goblin(name);
				fight.addCharacter(newGoblin);
				break;
			}
			case 2:
			{
				Barbarian *newBarbarian = new Barbarian(name);
				fight.addCharacter(newBarbarian);
				break;
			}
			case 3:
			{
				Reptile *newReptile = new Reptile(name);
				fight.addCharacter(newReptile);
				break;
			}
			case 4:
			{
				BlueMen *newBlueMen = new BlueMen(name);
				fight.addCharacter(newBlueMen);
				break;
			}
			case 5:
			{
				Shadow *newShadow = new Shadow(name);
				fight.addCharacter(newShadow);
				break;
			}
			default: {
				cout << "You must select between 1 and 5" << endl;

			}
			}
			break;
		}
		case 2:
		{
			cout << "Enter Charater name you want to remove:";
			getline(cin, name);
			fight.removeCharacter(name);
			break;
		}
		case 3: //fight
		{
			cout << "What character would you like to attack with? " << endl;
			getline(cin, name);
			attacker = fight.getCharacter(name);

			cout << "What Charater is defending:" << endl;
			getline(cin, name);
			defender = fight.getCharacter(name);

			fight.fight(attacker, defender);

			cout << "Would you like to fight again (y/n): " << endl;
			cin >> answer;

			while (answer == 'y')
			{
				fight.fight(attacker, defender);

				cout << "Would you like to fight again (y/n): " << endl;
				cin >> answer;
			}

			break;
		}
		case 4: 
		{
			cout << "Thank you for playing! " << endl;
		}
		}
	}

	return 0;
}