/*********************************************************************
** Author: Sean Reilly
** Date: April 23, 2015 CS-162
** Description: main for grocery list program
*********************************************************************/

#include <iostream>
#include "Item.h"
#include "GroceryList.h"

using namespace std;

int main() {
	int choice = 0;

	char answer = 'n';

	string newName;
	int newQuanity;
	double newPrice;
	string newUnit;

	List myList;

	while (choice != 4) //prints menu
	{
		cout << "Grocery List Program " << endl;
		cout << "Press 1 to add an item " << endl;
		cout << "Press 2 to remove an item " << endl;
		cout << "Press 3 to print the list " << endl;
		cout << "Press 4 to quit the program " << endl;
		cout << " " << endl;
		cout << "Please Enter Choice: ";
		cin >> choice;
		cin.ignore();


		switch (choice)
		{
		case 1:
		{
			cout << "Please enter the item name: ";
			getline(cin, newName);
			cout << "Please enter the item price: ";
			cin >> newPrice;
			cout << "What Is The Unit Type:";
			cin >> newUnit;
			cout << "Enter How Many Units: ";
			cin >> newQuanity;

			cout << "Is this a club item? (y/n?) ";
			cin >> answer;
			cout << " " << endl;

			if (answer == 'N' || answer == 'n') //is it a club item?
			{
				Item *nItem = new Item(newName, newQuanity, newPrice, newUnit);
				myList.addItem(nItem);
			}
			else
			{
				ClubItem *newClub = new ClubItem;
				newClub->setValues(newName, newQuanity, newPrice, newUnit);

				cout << "Is the club item on sale (y/n)? ";
				cin >> answer;

				if (answer == 'Y' || answer == 'y') //is item on sale?
				{
					newClub->salesCheck(true);
				}
				myList.addItem(newClub);
			}

			break;
		}

		case 2:
			cout << "What Item would you like removed (Enter Name): ";
			getline(cin, newName);
			myList.removeItem(newName);
			break;
		case 3:
		{
			myList.printList();
			cout << " " << endl;
			break;
		}

		case 4:
			cout << "Thank you, the program is now ending ";
			break;
		default:
			cout << "Please enter a number between 1 & 4 " << endl;
		}
	}


	return 0;
}