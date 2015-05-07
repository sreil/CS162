/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: transform to uppercase
*********************************************************************/

#include "upper.h"

const int LOWER_TO_UPPER = -32;

char UppercaseFilter::transform(char ch)
{
	if ((int)ch >= 97 && (int)ch <= 122)
	{
		return (char)((int)ch + LOWER_TO_UPPER);
	}
	else
	{
		return ch;
	}
}