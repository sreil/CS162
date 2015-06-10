/*********************************************************************
** Author: Sean Reilly
** Date: May 23, 2015 CS-162
** Description: first in last out class
*********************************************************************/

#include "lastOut.h"

using namespace std;

LO::LO() //constructor
{
	head = NULL;
	count = 0;
}
LO::~LO() //deconstructor
{
	while (head != NULL)
	{
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

bool LO::isEmpty() const //see if queue is empty
{
	if (!head)
		return true;
	else
		return false;
}

void LO::push(int number) //add link to list
{
	head = new node(number, head);
	count = count + 1;
}

void LO::pop() //remove top of the stack
{
	int num;
	node* temp;

	if (isEmpty())
	{
		cout << "The list is empty" << endl;
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

int LO::peek() //return top value
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		return head->value;
	}
}

int LO::getCount() //returns how many nodes are in the queue
{
	return count;
}