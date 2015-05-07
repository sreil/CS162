/*********************************************************************
** Author: Sean Reilly
** Date: April 21, 2015 CS-162
** Description: Merge 2 files into 1
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* OUT_FILE_NAME = "output.txt";

void Merge(string file1, string file2)
{
	ifstream f1;
	ifstream f2;
	ofstream output;


	f1.open(file1.c_str());
	f2.open(file2.c_str());
	output.open(OUT_FILE_NAME);
	
	int fileValue1;
	int fileValue2;
	bool fileValue1Used = true;
	bool fileValue2Used = true;
	bool fileContinue1 = true;
	bool fileContinue2 = true;

	if (f1 && f2 && output)
	{
		do
		{
			if (fileContinue1 && fileValue1Used)
			{
				if (f1 >> fileValue1)
				{
					fileValue1Used = false;
				}
				else
				{
					fileContinue1 = false;
				}
			}
			if (fileContinue2 && fileValue2Used)
			{
				if (f2 >> fileValue2)
				{
					fileValue2Used = false;
				}
				else
				{
					fileContinue2 = false;

				}
			}

			if (!fileContinue1 && fileContinue2)
			{
				output << fileValue2 << '\n';
				fileValue2Used = true;


			}
			else if (fileContinue1 && !fileContinue2)
			{
				output << fileValue1 << endl;
				fileValue1Used = true;
			}
			else if ((fileValue1 > fileValue2) && (fileContinue1 && fileContinue2))
			{
				output << fileValue2 << endl;
				fileValue2Used = true;
			}
			else if ((fileValue1 < fileValue2) && (fileContinue1 && fileContinue2))
			{
				output << fileValue1 << endl;
				fileValue1Used = true;
			}
			else if ((fileValue1 == fileValue2) && (fileContinue1 && fileContinue2))
			{
				output << fileValue1 << " " << fileValue2 << endl;
				fileValue1Used = true;
				fileValue2Used = true;
			}



		} while (fileContinue1 || fileContinue2);

	}
	else
	{
		std::cout << "ERROR!" << std::endl;

		if (!f1)
		{
			cout << "Unable to read from file: " << file1 << endl;
		}
		if (!f2)
		{
			cout << "Unable to read from file: " << file2 << endl;
		}
		if (!output)
		{
			cout << "Unable to write to file: " << OUT_FILE_NAME << endl;
		}
	}

	f1.close();
	f2.close();
	output.close();


}

int main()
{
	Merge("file1.txt", "file2.txt");

	cout << "The merged file can be found in output.txt " << endl;
	return 0;
}