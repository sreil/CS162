/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: encrypt header
*********************************************************************/

#pragma once

#include "dofilter.h"

using namespace std;

class EncryptFilter : public FileFilter
{
public:
	EncryptFilter(int encrypt);
private:
	int encrypt;

	virtual char transform(char ch);

};