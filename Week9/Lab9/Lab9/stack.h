/*********************************************************************
** Author: Sean Reilly
** Date: May 29, 2015 CS-162
** Description: stack header
*********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <stack>

using namespace std;

class Stack {

public:
	void create();
	void test();

private:
	stack<char> stack;
};

#endif