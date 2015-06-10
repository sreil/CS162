/*********************************************************************
** Author: Sean Reilly
** Date: May 7, 2015 CS-162
** Description: menu and implementation of battles for fighting game
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <vector>
#include <queue>
#include <stack>
#include "type.h"

using namespace std;

void generate(queue<type*>& lineup, int fighters, string team);
void combat(type* player1, type* player2);
void tournament(queue<type*>& lineup1, stack<type*>& loser1, queue<type*>& lineup2, stack<type*>& loser2);
void results(queue<type*>& lineup1, stack<type*>& loser1, queue<type*>& lineup2, stack<type*>& loser2);
int inputInt(int lower, int upper);
int inputInt(int lower);
string isEmpty();

int main()
{
	srand(time(NULL));

	queue<type*> lineup1;
	queue<type*> lineup2;
	stack<type*> loser1;
	stack<type*> loser2;

	int fighter;
	string team1, team2;

	cout << "Welcome to the tournament!" << endl;
	cout << "Two teams will fight, choose wisely. " << endl;

	cout << "How many fighters would you like per team? " << endl;

	fighter = inputInt(1);

	cout << "Please choose your characters for player 1 " << endl;
	cout << "What would you like the team name to be? " << endl;

	team1 = isEmpty();
	generate(lineup1, fighter, team1);
	cout << endl;

	cout << "Thank you.  Now please choose your characters for player 2 " << endl;
	cout << "What would you like the team name to be? " << endl;
	
	team2 = isEmpty();
	while (team2 == team1)
	{
		cout << "Please enter a different team name" << endl;
		team2 = isEmpty();
	}
	generate(lineup2, fighter, team2);
	cout << endl;

	tournament(lineup1, loser1, lineup2, loser2);

	results(lineup1, loser1, lineup2, loser2);

	cout << "Thanks for playing!" << endl;

	return 0;
}


void generate(queue<type*>& lineup, int fighters, string team)
{
	for (int i = 0; i < fighters; i++)
	{
		cout << "Press 1 to be a goblin" << endl;
		cout << "Press 2 to be a barbarian" << endl;
		cout << "Press 3 to be the reptile people" << endl;
		cout << "Press 4 to be the blue people" << endl;
		cout << "Press 5 to be the shadow" << endl;
		cout << " " << endl;
		cout << "Please enter your choice now: " << endl;
		int choice;
		choice = inputInt(1, 5);

		string name;
		cout << "What's your fighter's name? " << endl;
		name = isEmpty();

		switch (choice)
		{
		case 1:
		{
			type* temp = new Goblin(name, team);
			lineup.push(temp);
			break;
		}
		case 2:
		{
			type* temp = new Barbarian(name, team);
			lineup.push(temp);
			break;
		}
		case 3:
		{
			type* temp = new Reptile(name, team);
			lineup.push(temp);
			break;
		}
		case 4:
		{
			type* temp = new BlueMen(name, team);
			lineup.push(temp);
			break;
		}
		case 5:
		{
			type* temp = new Shadow(name, team);
			lineup.push(temp);
			break;
		}

		}
	}
}

void combat(type* player1, type* player2) //fight
{
	cout << player1->showTeam() << "'s " << player1->showName() << " the " << player1->showType() << " vs " << player2->showTeam() << "'s " << player2->showName() << " the " << player2->showType() << endl;
	int random;
	random = rand() % 2;
	if (random == 0)
	{
		cout << player1->showTeam() << "'s " << player1->showName() << " the " << player1->showType() << " goes first" << endl;
		while (player1->isAlive() && player2->isAlive())
		{
			player1->fight(player1, player2);
			if (player2->isAlive())
			{
				player1->fight(player2, player1);
			}
		}
	}
	else
	{
		cout << player2->showTeam() << "'s " << player2->showName() << " the " << player2->showType() << " goes first" << endl;
		while (player1->isAlive() && player2->isAlive())
		{
			player2->fight(player2, player1);
			if (player1->isAlive())
			{
				player2->fight(player1, player2);
			}
		}
	}

	if (player1->isAlive())
	{
		cout << player2->showTeam() << "'s " << player2->showName() << " the " << player2->showType() << " is dead.  That means " << player1->showTeam() << "'s " << player1->showName() << " the " << player1->showType() << " wins" << endl;
	}
	else
	{
		cout << player1->showTeam() << "'s " << player1->showName() << " the " << player1->showType() << " is dead.  That means  " << player2->showTeam() << "'s " << player2->showName() << " the " << player2->showType() << " wins" << endl;
	}

	if (player1->isAlive())
	{
		player1->strengthAdd();
		player1->addPoints(player2);
		cout << player1->showTeam() << "'s " << player1->showName() << " the " << player1->showType() << " has " << player1->showPoints() << " points" << endl;
	}
	else
	{
		player2->strengthAdd();
		player2->addPoints(player1);
		cout << player2->showTeam() << "'s " << player2->showName() << " the " << player2->showType() << " has " << player2->showPoints() << " points." << endl;
	}
}
	
void tournament(queue<type*>& lineup1, stack<type*>& loser1, queue<type*>& lineup2, stack<type*>& loser2)
{
	cout << "The fighting has started...good luck" << endl;
	while (lineup1.size() > 0 && lineup2.size() > 0)
	{
		type* unit1 = lineup1.front();
		type* unit2 = lineup2.front();
		lineup1.pop();
		lineup2.pop();

		combat(unit1, unit2);
		cout << "This round is over" << endl << endl << endl;

		if (unit1->isAlive())
		{
			lineup1.push(unit1);
			loser2.push(unit2);
		}
		else
		{
			loser1.push(unit1);
			lineup2.push(unit2);
		}
	}
}

void results(queue<type*>& lineup1, stack<type*>& loser1, queue<type*>& lineup2, stack<type*>& loser2) //outputs tournament results
{
	vector<type*> standings;

	string lastTeam;
	if (!lineup1.empty())
	{
		lastTeam = lineup1.front()->showTeam();
	}
	else
	{
		lastTeam = lineup2.front()->showTeam();
	}

	string team1;
	if (!lineup1.empty())
	{
		team1 = lineup1.front()->showTeam();
	}
	else
	{
		team1 = loser1.top()->showTeam();
	}

	string team2;
	if (!lineup2.empty())
	{
		team2 = lineup2.front()->showTeam();
	}
	else
	{
		team2 = loser2.top()->showTeam();
	}
	int teamPts1 = 0;
	while (!lineup1.empty())
	{
		teamPts1 += lineup1.front()->showPoints();
		standings.push_back(lineup1.front());
		lineup1.pop();
	}
	while (!loser1.empty())
	{
		teamPts1 += loser1.top()->showPoints();
		standings.push_back(loser1.top());
		loser1.pop();
	}

	int teamPts2 = 0;
	while (!lineup2.empty())
	{
		teamPts2 += lineup2.front()->showPoints();
		standings.push_back(lineup2.front());
		lineup2.pop();
	}
	while (!loser2.empty())
	{
		teamPts2 += loser2.top()->showPoints();
		standings.push_back(loser2.top());
		loser2.pop();
	}
	type* temp;
	bool swap;
	do
	{
		swap = false;
		for (unsigned int i = 0; i < (standings.size() - 1); i++) //bubble sort
		{
			if (standings.at(i)->showPoints() <
				standings.at(i + 1)->showPoints())
			{
				temp = standings.at(i);
				standings.at(i) = standings.at(i + 1);
				standings.at(i + 1) = temp;
				swap = true;
			}
		}
	} while (swap);

	cout << "Team results: " << endl;
	cout << "The team with the last member(s) standing: " << lastTeam << "!" << endl;

	if (teamPts1 > teamPts2)
	{
		cout << team1 << " wins with a total of " << teamPts1 << " points" << endl;
		cout << team2 << " only had " << teamPts2 << " points.  Nice try" << endl;
	}
	else if (teamPts2 > teamPts1)
	{
		cout << team2 << " wins with a total of " << teamPts2 << " points!" << endl;
		cout << team1 << " only had " << teamPts1 << " points. Nice try" << endl;
	}
	else
	{
		cout << team1 << " and " << team2 << " tied with " << teamPts1 << " points each!" << endl;
	}

	cout << "Individual results: " << endl;
	if (standings.size() < 3)
	{
		cout << "You need at least 3 fighters to see the top 3! " << endl;
	}
	else
	{
		cout << "First place: ";
		cout <<	standings.at(0)->showTeam() << "'s "
			 << standings.at(0)->showName() << " the "
			 << standings.at(0)->showType() << ", with "
			 << standings.at(0)->showPoints() << " points" << endl;
		cout << "Second place: " 
			 << standings.at(1)->showTeam() << "'s "
			 << standings.at(1)->showName() << " the "
			 << standings.at(1)->showType() << ", with "
			 << standings.at(1)->showPoints() << " points" << endl;
		cout << "Third place: "
			 << standings.at(2)->showTeam() << "'s "
			 << standings.at(2)->showName() << " the "
			 << standings.at(2)->showType() << ", with "
			 << standings.at(2)->showPoints() << " points" << endl;
	}

	cout << " " << endl;
	cout << " " << endl;
	for (unsigned int i = 0; i < standings.size(); i++)
	{
		type* temp2 = standings.at(i);
		delete temp2;
	}

	standings.clear();
}

int inputInt(int lower, int upper)
{
	int tempNum;
	cin >> tempNum;
	while (cin.fail() || (tempNum < lower || tempNum > upper))
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter an integer from " << lower << " to "
			<< upper << ": ";
		cin >> tempNum;
	}
	cin.ignore();
	return tempNum;
}

int inputInt(int lower)
{
	int temp;
	cin >> temp;
	while (cin.fail() || (temp <= lower))
	{
		cin.clear();
		cin.ignore();
		cout << "Please enter an integer greater than " << lower << ": ";
		cin >> temp;
	}
	cin.ignore();
	return temp;
}

string isEmpty() //checks if input is empty
{
	string temp2("");
	getline(cin, temp2);
	while (temp2.length() == 0 || cin.fail())
	{
		cout << "You have to enter something! " << endl;
		getline(cin, temp2);
	}
	return temp2;
}