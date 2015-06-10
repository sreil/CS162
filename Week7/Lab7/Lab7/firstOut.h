/*********************************************************************
** Author: Sean Reilly
** Date: May 14, 2015 CS-162
** Description: first in first out function header
*********************************************************************/

#ifndef FIRSTOUT_H
#define FIRSTOUT_H
#include <iostream>

class FO
{
public:
	FO() 
	{
		head = NULL;
	}
	~FO(); 
	void add(int number);
	int remove();
	void print();

protected:
	struct node
	{
		int value;
		node *next;
		node *prev;
		node(int value1, node * next1 = NULL, node *prev1 = NULL)
		{
			value = value1;
			next = next1;
			prev = prev1;
		}
	};
	node *head;
};
#endif