/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: Read input file and transform it
*********************************************************************/

#include "doFilter.h"

using namespace std;

void FileFilter::doFilter(ifstream &in, ofstream &out)
{
	while ((in.peek() != EOF))
	{
		char inChar;
		char outChar;
		in.get(inChar);
		outChar = transform(inChar);
		out.put(outChar);
	}

}