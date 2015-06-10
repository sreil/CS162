/*********************************************************************
** Author: Sean Reilly
** Date: May 6, 2015 CS-162
** Description: header that contains all different options
*********************************************************************/

#include <fstream>

#ifndef FIND_H
#define FIND_H

using namespace std;

class Find
{
public:
	void targetSearch(ifstream&, int);
	void bubble(ifstream&, ofstream&);
	void binary(ifstream&, int);
};

#endif