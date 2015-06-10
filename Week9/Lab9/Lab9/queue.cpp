/*********************************************************************
** Author: Sean Reilly
** Date: May 29, 2015 CS-162
** Description: queue class
*********************************************************************/

#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	randomNum = 0;
	queueAverage = 0;
	count = 0;
}

int Queue::random()
{
	int randomNum;

	srand(time(NULL)); //generate random number
	randomNum = rand() % 100 + 1;
	cout << "The random number is: " << randomNum << endl;
	return randomNum;
}

void Queue::queueAdd(int percent) //add number to queue
{
	int addTest = 0;
	addTest = random();
	cout << addTest << endl;

	if (addTest <= percent)
	{
		queue.push(randomNum);
		cout << "That random number was added to the queue" << endl;
	}
	else
	{
		cout << "Sorry your random number was not added to queue" << endl;
	}
	count++;
	queueAverage += queue.size();

	displayQueue();
}

void Queue::remove(int percent) //remove number from queue
{
	if (!queue.empty()) 
	{
		int removeTest = 0;

		removeTest = random();

		if (removeTest <= percent)
		{
			cout << "Number removed was " << queue.front() << endl;
			queue.pop();

		}
		else
		{
			cout << "Sorry the number wasn't removed from the queue" << endl;
		}
	}
	else
	{
		cout << "The queue is empty " << endl;
	}
	
	count++;
	queueAverage += queue.size();

	displayQueue();
}

void Queue::displayQueue()
{
	cout << "The average queue length is: " << queueAverage / (double)count;
}