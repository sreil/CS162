/*********************************************************************
** Author: Sean Reilly
** Date: May 14, 2015 CS-162
** Description: Lab7 main.cpp
*********************************************************************/

#include <iostream>
#include "firstOut.h"
#include "lastOut.h"

using namespace std;

int main()
{
	cout << "Demomnstrating first in, last out to start" << endl;
	cout << " " << endl;

	LO lo;
	std::cout << "Adding 3 nodes to the stack in this order 43, 17 and 28" << std::endl;

	lo.add(43);
	lo.add(17);
	lo.add(28);

	cout << "The current stack is: ";
	lo.print();

	cout << " " << endl;
	cout << "Now we will remove the top of the stack" << endl;
	cout << "Number removed is: " << lo.remove() << endl;

	cout << "Now we will add additional numbers.  Let's add 15 & 103 to the stack" << endl;
	lo.add(15);
	lo.add(103);

	cout << "The current stack is now: " << endl;
	lo.print();

	cout << " " << endl;
	cout << "Now let's remove the top 3 from the stack" << endl;

	for (int i = 0; i<3; i++)
	{
		cout << "We removed the following: " << lo.remove() << endl;
	}

	cout << "The current stack is now: " << endl;
	lo.print();

	cout << " " << endl;
	cout << "That concludes the first in, last out part of the demonstration " << endl;

	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Now we will demonstrate first in, first out" << endl;
	
	FO fo;
	cout << "Adding 3 nodes to the que in this order 19, 31, 75" << std::endl;

	fo.add(19);
	fo.add(31);
	fo.add(75);

	cout << "The current stack is now: " << endl;
	fo.print();

	cout << " " << endl;
	cout << "Now let's remove the top from the stack" << endl;
	cout << "Removed " << fo.remove() << endl;

	cout << "Now let's add 431 and 23 to the list" << endl;
	fo.add(431);
	fo.add(23);

	cout << "The current stack is now: " << endl;
	fo.print();

	system("pause");

	return 0;
}