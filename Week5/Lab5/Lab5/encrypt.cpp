/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: encrypt
*********************************************************************/

#include <iostream>
#include "encrypt.h"

EncryptFilter::EncryptFilter(int encrypt)
{
	this->encrypt = encrypt;
}

char EncryptFilter::transform(char ch)
{
	if ((int)ch >= 65 && (int)ch <= 90)
	{
		return (((((int)ch) + this->encrypt) % 26) + 65);
	}
	else if ((int)ch >= 97 && (int)ch <= 122)
	{
		return (((((int)ch) + this->encrypt) % 26) + 97);
	}
	else
	{
		return ch;
	}
	
}