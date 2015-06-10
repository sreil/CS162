/*********************************************************************
** Author: Sean Reilly
** Date: May 29, 2015 CS-162
** Description: stack class
*********************************************************************/

#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

void Stack::create() //create a palindrome, replace letters as needed
{
	stack.push('l');
	stack.push('e');
	stack.push('p');
	stack.push('e');
	stack.push('r');
	stack.push('s');
	stack.push('r');
	stack.push('e');
	stack.push('p');
	stack.push('e');
	stack.push('l');
}

void Stack::test() //tests if a palindrome or not
{
	string combo;

	while (!stack.empty())
	{
		combo += stack.top();
		stack.pop();
	}

	if (combo == string(combo.rbegin(), combo.rend()))
	{
		cout << "yay! " << combo << " is a palindrome!" << endl;
	}
	else
	{
		cout << combo << " is not a plindrome!" << endl;
	}
}