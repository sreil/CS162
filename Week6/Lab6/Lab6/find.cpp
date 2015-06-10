/*********************************************************************
** Author: Sean Reilly
** Date: May 6, 2015 CS-162
** Description: code related to the find header
*********************************************************************/

#include "find.h"
#include <iostream>
#include <fstream>

using namespace std;

void Find::targetSearch(ifstream& fileIn, int search)
{
	int number, counter = 0, numArr[20];

		while (fileIn >> number)
		{
			numArr[counter] = number;
			counter++;
		}

	for (int i = 0; i < 19; i++)
	{
		if (numArr[i] == search)
		{
			cout << "We found " << search << " at spot " << i << endl;
			break;
		}
	}
}
void Find::bubble(ifstream& fileIn, ofstream& fileOut)
{
	int number, temp, numArr[20], counter = 0;

	while (fileIn >> number)
	{
		numArr[counter] = number;
		counter++;
	}

	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j<19; j++)
		{
			if (numArr[j]>numArr[j + 1])
			{
				temp = numArr[j];
				numArr[j] = numArr[j + 1];
				numArr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i <= 19; i++)
	{
		fileOut << numArr[i] << std::endl;
	}
}
void Find::binary(ifstream& fileIn, int search)
{
	int number, temp, numArr[20], counter = 0, start = 1, end = 20;
	int mid = (start + end) / 2;

	while (fileIn >> number)
	{
		numArr[counter] = number;
		counter++;
	}

	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j<19; j++)
		{
			if (numArr[j]>numArr[j + 1])
			{
				temp = numArr[j];
				numArr[j] = numArr[j + 1];
				numArr[j + 1] = temp;
			}
		}
	}

	//binary search for 0
	while (start <= end&&numArr[mid] != search)
	{
		if (numArr[mid] < search)
		{
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
		mid = (start + end) / 2;
	}

	if (numArr[mid] == search)
		
		cout << "If was found here: " << search << endl;
	else
	{
		cout << "Your search of " << search << " was not Found" << endl;
	}
}