/*********************************************************************
** Author: Sean Reilly
** Date: April 23, 2015 CS-162
** Description: GroceryList.cpp - prints lists, adds items, removes items
*********************************************************************/

#include <iostream>
#include <vector> //for vectors
#include <iomanip> //for set precision
#include "GroceryList.h"
#include "Item.h"

using namespace std;

List::List()
{
	vector<Item> GroceryList;
}

void List::addItem(Item *item)
{
	GroceryList.push_back(item);
}

void List::removeItem(std::string newName)
{
	for (int i = 0; i < GroceryList.size(); i++)
	{
		if (GroceryList[i]->getName() == newName)
		{
			GroceryList.erase(GroceryList.begin() + i);
		}
	}
}

void List::printList()
{
	for (int i = 0; i < GroceryList.size(); i++)
	{
		cout << '\n' << GroceryList[i]->getName() << " " << GroceryList[i]->getQty() << " " <<
			GroceryList[i]->getUnit() << " $" << setprecision(2) << fixed << GroceryList[i]->getPrice() <<
			setprecision(2) << fixed << " $" << GroceryList[i]->getSubTotal();
	}
	cout << " " << endl;
	viewTotal();
}


void List::viewTotal()
{
	double total = 0;

	for (int i = 0; i < GroceryList.size(); i++)
	{
		total += GroceryList[i]->getSubTotal();
	}

	cout << "Current Total is $" << setprecision(2) << fixed << total << endl;
}