/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: transform to uppercase header
*********************************************************************/

#pragma once

#include "doFilter.h"

class UppercaseFilter : public FileFilter
{
private:
	virtual char transform(char ch);
};