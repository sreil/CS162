/*********************************************************************
** Author: Sean Reilly
** Date: May 23, 2015 CS-162
** Description: first in first out class
*********************************************************************/

#include "firstOut.h"

using namespace std;

FO::FO() //constructor
{
	head = NULL;
	tail = NULL;
	count = 0; 
}
FO::~FO() //deconstructor
{
	while (head != NULL)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

bool FO::isEmpty() const //test if empty
{
	if (!head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int FO::getFront() // for top int on the queue
{
	if (isEmpty())
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		return head->value;
	}
}

void FO::addBack(int number) //add link to list
{
	if (isEmpty())
	{
		head = new node(number);
		tail = head;
	}
	else
	{
		tail->next = new node(number);
		tail = tail->next;
	}
	count = count + 1;
}

void FO::removeFront() //remove first link
{
	node* temp;
	int num;
	if (isEmpty())
	{
		cout << "The queue is empty" << endl;
	}
	else
	{
		num = head->value;
		temp = head;
		head = head->next;
		delete temp;
	}
	count = count - 1;
}

int FO::getCount() //returns how many nodes
{
	return count;
}