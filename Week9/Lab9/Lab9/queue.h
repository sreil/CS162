/*********************************************************************
** Author: Sean Reilly
** Date: May 29, 2015 CS-162
** Description: queue header
*********************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <queue>

using namespace std;

class Queue {

public:
	Queue(); //default constructor
	int random();
	void queueAdd(int);
	void remove(int);

private:
	queue<int> queue;
	int randomNum;
	int queueAverage;
	int count;
	void displayQueue();
};

#endif