#include <iostream>

using namespace std;
void smallSort(int*, int*, int*);

int main()
{
    int num1, num2, num3;
    cout << "Please enter the first number" << endl;
    cin >> num1;
    cout << "Please enter the second number" << endl;
    cin >> num2;
    cout << "Please enter the third number" << endl;
    cin >> num3;

    cout << "You entered " << num1 << ", " << num2 << ", and " << num3 << endl;
    cout << "Now I will sort from smallest to largest!" << endl;

    smallSort(&num1, &num2, &num3);

    return 0;
}

void smallSort(int *pnt1, int *pnt2, int *pnt3)
{
    int nums[3] = {*pnt1,*pnt2,*pnt3};
	int temp;

    for(int i = 0; i <= 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(nums[j] > nums[j+1])
			{
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}

	cout << "Your sorted numbers are " << endl;

	for(int k = 0; k < 3; k++)
	{
	cout << nums[k] << endl;
	}
}
