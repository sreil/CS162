/*********************************************************************
** Author: Sean Reilly
** Date: April 23, 2015 CS-162
** Description: header for grocerylist.cpp
*********************************************************************/

#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

#ifndef LIST_H
#define LIST_H


class List {

private:
	vector<Item*> GroceryList;

public:
	List();

	void addItem(Item*);
	void removeItem(string);
	void printList();
	void viewTotal();
};


#endif