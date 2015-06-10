/*********************************************************************
** Author: Sean Reilly
** Date: May 14, 2015 CS-162
** Description: first in first out function
*********************************************************************/

#include "firstOut.h"

using namespace std;

FO::~FO()
{
	node *pointer = head;  //Start head of the list
	while (pointer != NULL)
	{
		// del keeps track of node to be deleted
		node *del = pointer;
		pointer = pointer->next;
		delete del; //delete the bad node
	}
}

void FO::add(int number) //adds link to end of list
{
	if (head == NULL)
	{
		head = new node(number); 
	}
	else
	{
		node* pointer = head;
		while (pointer->next != NULL)   //go to end
		{
			pointer = pointer->next;
		}
		pointer->next = new node(number, NULL, pointer);

	}
}

int FO::remove() //removes the first link of the list then returns value
{
	int numberRemoved;
	node *temp;

	if (head == NULL)
	{
		return 0; 
	}
	else if (head->next == NULL)
	{
		numberRemoved = head->value;
		delete head;
	}
	else
	{
		temp = head->next;
		numberRemoved = head->value;
		delete head;

		head = temp; //Sets head as the next value
		head->prev = NULL;
	}
	return numberRemoved;
}

void  FO::print() //prints list
{
	node *pointer = head; //start at list head
	while (pointer)
	{
		cout << pointer->value << "  ";
		pointer = pointer->next;
	}
}