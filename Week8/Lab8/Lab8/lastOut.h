/*********************************************************************
** Author: Sean Reilly
** Date: May 23, 2015 CS-162
** Description: first in last out header
*********************************************************************/

#ifndef LASTOUT_H
#define LASTOUT_H

#include <iostream>

class LO
{
public:
	LO();
	~LO();
	void push(int);
	int peek();
	void pop();
	bool isEmpty() const;
	int getCount();

protected:
	struct node
	{
		int value;
		node* next;
		node(int value1, node* next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	node* head;
private:
	int count;
};
#endif