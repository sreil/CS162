/*********************************************************************
** Author: Sean Reilly
** Date: May 23, 2015 CS-162
** Description: menu for queue and stack
*********************************************************************/

#include <iostream>
#include "lastOut.h"
#include "firstOut.h"

using namespace std;

int main()
{

	FO fifo; //for queue
	LO lifo; //for stack

	int choice = 0;
	int inputNumber;
	int numbersToAdd;


	while (choice != 5) {
		cout << "Stack And Queue Menu" << endl;
		cout << "Press 1 to add numbers to the stack" << endl;
		cout << "Press 2 to add numbers to the queue" << endl;
		cout << "Press 3 to remove numbers from the stack" << endl;
		cout << "Press 4 to remove numbers from the queue" << endl;
		cout << "Press 5 to exit the program" << endl;

		cout << "Please enter choice now: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: 
		{
			cout << "How many numbers would you like to add? " << endl;
			cin >> numbersToAdd;

			for (int i = 0; i < numbersToAdd; i++) {
				cout << "Add Number: ";
				cin >> inputNumber;
				lifo.push(inputNumber);
			}
			break;
		}
		case 2: 
		{
			cout << "How many numbers would you like to add: ";
			cin >> numbersToAdd;

			for (int i = 0; i < numbersToAdd; i++) {
				cout << "Add Number: ";
				cin >> inputNumber;
				fifo.addBack(inputNumber);
			}
			break;
		}
		case 3:
		{
			cout << "How many numbers would you like to remove from the stack: ";
			cin >> numbersToAdd;

			if (fifo.getCount() < numbersToAdd)
			{
				cout << "Not enough number in stack to remove" << endl;
			}
			else {
				for (int i = 0; i < numbersToAdd; i++)
				{
					cout << "Number removing " << lifo.peek() << endl;
					lifo.pop();
				}
			}
			break;
		}
		case 4: 
		{
			cout << "How many numbers would you like to remove from the queue: ";
			cin >> numbersToAdd;

			if (fifo.getCount() < numbersToAdd)
			{
				cout << "Not enough number in queue to remove" << endl;
			}
			else {
				for (int i = 0; i < numbersToAdd; i++)
				{
					cout << "Number removing " << fifo.getFront() << endl;
					fifo.removeFront();
				}
			}
			break;
		}
		}
	}
	return 0;
}