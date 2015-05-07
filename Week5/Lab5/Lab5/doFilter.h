/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: Read input file and transform it
*********************************************************************/

#pragma once  //included to source file will only do one compilation

#include <fstream>

using namespace std;

class FileFilter
{
public:
	virtual void doFilter(ifstream &in, ofstream &out);

private:
	virtual char transform(char ch) = 0;
};