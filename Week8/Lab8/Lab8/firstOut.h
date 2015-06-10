/*********************************************************************
** Author: Sean Reilly
** Date: May 23, 2015 CS-162
** Description: first in first out header
*********************************************************************/

#ifndef FIRSTOUT_H
#define FIRSTOUT_H
#include <iostream>

class FO {
public:
	FO();
	~FO();

	void addBack(int);
	int getFront();
	void removeFront();
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
	node* tail;

private:
	int count;
};

#endif

