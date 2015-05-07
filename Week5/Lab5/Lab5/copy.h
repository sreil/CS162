/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: copies to another file header
*********************************************************************/

#pragma once

#include "doFilter.h"

using namespace std;

class CopyFilter : public FileFilter
{
private:
	virtual char transform(char ch);
};