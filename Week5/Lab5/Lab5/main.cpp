/*********************************************************************
** Author: Sean Reilly
** Date: May 1, 2015 CS-162
** Description: Read input file and transform it
*********************************************************************/

#include <iostream>
#include <string>
#include "doFilter.h"
#include "copy.h"
#include "upper.h"
#include "encrypt.h"

//ran out of time for cipher

using namespace std;


int main()
{
	ifstream copyIn;
	ofstream copyOut;

	//check if file opens or not
	copyIn.open("original.txt");
	if (!copyIn.good())
	{
		cout << "File 'original.txt' cannot be found!" << std::endl;
	}
	else
	{
		copyIn.close();
	}


	//copy
	copyIn.open("original.txt");
	copyOut.open("copyOut.txt");
	CopyFilter *copyFilter = new CopyFilter();
	copyFilter->doFilter(copyIn, copyOut);
	copyIn.close();
	copyOut.close();
	
	//encrypt
	copyIn.open("original.txt");
	copyOut.open("encryptOut.txt");
	EncryptFilter *encryptFilter = new EncryptFilter(2); //adjust number here to shift as needed
	encryptFilter->doFilter(copyIn, copyOut);
	copyIn.close();
	copyOut.close();

	//uppercase
	copyIn.open("original.txt");
	copyOut.open("uppercaseOut.txt");
	UppercaseFilter *upcaseFilter = new UppercaseFilter();
	upcaseFilter->doFilter(copyIn, copyOut);
	copyIn.close();
	copyOut.close();

	return 0;
}