/*********************************************************************
** Author: Sean Reilly
** Date: May 29, 2015 CS-162
** Description: menu to display queue and stack
*********************************************************************/

#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main() {

	Queue queue;
	Stack stack;
	int choice = 0;
	int num = 0;
	
	while (choice != 5) {
		cout << " " << endl;
		cout << "Create two data structures: a stack and a queue" << endl;
		cout << "Press 1 to add a number to your buffer (queue)" << endl;
		cout << "Press 2 to remove a number from your buffer" << endl;
		cout << "Press 3 to create a palindrome (stack)" << endl;
		cout << "Press 4 to test your palindrome" << endl;
		cout << "Press 5 if you would like to exit the program" << endl;
		cout << "Please enter choice: " << endl;
		cin >> choice;
		
		switch (choice) {
		case 1:
		{
			cout << "How high would you like the chance to be for the number to be added to the queue (1-100)? " << endl;
			cin >> num;
			queue.queueAdd(num);
			break;
		}
		case 2:
		{
			cout << "How high would you like the chance to be for the number to be removed from the queue? " << endl;
			cin >> num;
			queue.remove(num);
			break;
		}
		case 3:
		{
			cout << "We have created the palindrome lepers repel just for you!" << endl;
			stack.create();
			break;
		}
		case 4:
		{
			stack.test();
			break;
		}
		case 5:
		{
			cout << "Thank you, ending program" << endl;
			break;
		}
		default:
		{
			cout << "Please select from 1 to 5 only " << endl;
		}
		}
	}
	return 0;
}