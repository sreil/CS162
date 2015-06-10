/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: stores the character names and attacks
*********************************************************************/

#include <iostream>
#include "Fight.h"

using namespace std;

void Fight::addCharacter(Character* character)
{
	CharacterList.push_back(character);
}

void Fight::removeCharacter(std::string name)
{
	for (int i = 0; i < CharacterList.size(); i++)
	{
		if (CharacterList[i]->getName() == name)
		{
			CharacterList.erase(CharacterList.begin() + i);
		}
	}
}

Character* Fight::getCharacter(std::string name)
{
	for (int i = 0; i < CharacterList.size(); i++)
	{
		if (CharacterList[i]->getName() == name)
		{
			return CharacterList[i];
		}
	}
}

void Fight::fight(Character* attacker, Character* defender)
{
	int attackValue = 0;
	int defenseValue = 0;
	int damageTaken = 0;

	int defenderStrPnt = defender->getStrength();

	attackValue = attacker->attack();

	if (attacker->getClassType() == "Goblin" && attackValue == 12)
	{
		defender->setAchilles(false);
	}

	defenseValue = defender->defend();

	if (defender->getAchilles() == false)
	{
		defenseValue = defenseValue / 2;
	}


	if ((damageTaken = attackValue - defender->getArmor() - defenseValue) < 0)
	{
		damageTaken = 0;
	}
	else
	{
		damageTaken = attackValue - defender->getArmor() - defenseValue;
		defenderStrPnt = defenderStrPnt - damageTaken;
		defender->setStrength(defenderStrPnt);
	}

	std::cout << "Attacker " << attacker->getName() << " had a attack value of " << attackValue << std::endl;
	if (defenseValue != 100 || defenseValue != 50)
	{
		std::cout << "Defender " << defender->getName() << " had a defense value of " << defenseValue << std::endl;
	}
	std::cout << "Damage taken was " << damageTaken << std::endl;

	if (defenderStrPnt <= 0)
	{
		std::cout << "Defender " << defender->getName() << " died" << std::endl;
		for (int i = 0; i < CharacterList.size(); i++)
		{
			if (CharacterList[i]->getName() == defender->getName())
			{
				CharacterList.erase(CharacterList.begin() + i);
			}
		}
	}
	else
	{
		std::cout << "Updated stats for " << defender->getName() << ": " << "Strenght Points:" << defender->getStrength()
			<< std::endl;
	}
}