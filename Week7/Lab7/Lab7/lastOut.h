/*********************************************************************
** Author: Sean Reilly
** Date: May 14, 2015 CS-162
** Description: first in last out function header
*********************************************************************/

#ifndef LASTOUT_H
#define LASTOUT_H

#include <iostream>

class LO
{
public:
	LO() 
	{
		head = NULL;
	}
	~LO();
	void add(int number);
	int remove();
	void print();

protected:
	struct node
	{
		int value;
		node *next;
		node(int value1, node * next1 = NULL)
		{
			value = value1;
			next = next1;
			
		}
	};
	node *head; 
};


#endif