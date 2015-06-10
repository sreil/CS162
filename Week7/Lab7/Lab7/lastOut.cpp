/*********************************************************************
** Author: Sean Reilly
** Date: May 14, 2015 CS-162
** Description: first in last out function
*********************************************************************/

#include "lastOut.h"

using namespace std;

LO::~LO()
{
	node *pointer = head;  //Start head of the list
	while (pointer != NULL)
	{
		
		node *del = pointer;
		pointer = pointer->next;
		delete del;
	}
}


void LO::add(int number) //adds link
{
	if (head == NULL)
		head = new node(number);
	else
	{
		head = new node(number, head);
	}
}

int LO::remove() //removes last 
{
	node *pointer;
	int numRemoved;

	if (!head)
	{
		return head->value;
	}
	else
	{
		pointer = head;
		numRemoved = head->value;
		head = head->next;
		delete pointer; // Delete node
		return numRemoved;
	}

}

void  LO::print() //prints
{
	node *pointer = head; 
	while (pointer)
	{
		cout << pointer->value << "  ";
	
		pointer = pointer->next;
	}
}