/*********************************************************************
** Author: Sean Reilly
** Date: May 6, 2015 CS-162
** Description: menu that lets you choose which option you want --- either bubble sort, target value search or binary
*********************************************************************/

#include <iostream>
#include <string>
#include "find.h"

using namespace std;

int main()
{
	Find find;

	int choice = 0, search = 0;

	string inFileName = "";
	string outFileName = "";

	while (choice != 4) //prints menu
	{
		cout << "Options: " << endl;
		cout << "Press 1 to search for the target value " << endl;
		cout << "Press 2 to sort a set of values " << endl;
		cout << "Press 3 to do a binary search " << endl;
		cout << "Press 4 to quit the program " << endl;
		cout << " " << endl;
		cout << "Please Enter Choice: ";
		cin >> choice;
		cin.ignore();

		switch (choice)
		{
		case 1:
		{
				cout << "Please type the filename that you would like to manipulate: ";
				getline(cin, inFileName);
				cout << "Please enter the value you wish to search for: " << endl;
				cin >> outFileName;
				ifstream ifs(inFileName.c_str(), ios::in);
				find.targetSearch(ifs, search);
		}
		case 2:
		{
				cout << "Please type the filename that you would like to sort: " << endl;
				getline(cin, inFileName);
				cout << "Please tell me what you would like the sorted file to be named " << endl;
				getline(cin, outFileName);
		}
		case 3:
		{
				cout << "Please type the filename that you would like to manipulate: ";
				getline(cin, inFileName);
				cout << "Please enter the value you wish to search for: " << endl;
				cin >> outFileName;
				ifstream ifs(inFileName.c_str(), ios::in);
				find.binary(ifs, search);
		}
		case 4:
			cout << "Thank you, the program is now ending ";
			break;
		default:
			cout << "Please enter a number between 1 & 4 " << endl;

			return 0;
		}
	}
}