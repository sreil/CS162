/*********************************************************************
** Author: Sean Reilly
** Date: June 5, 2015 CS-162
** Description: main fibonacci numbers....code sourced here: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C first google result for this query, kept same file names
*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "FibonacciR.h"
#include "FibonacciNR.h"
#include <ctime>
#include "time.h"

using namespace std;

long rfactorial(int);
long factorialHelper(int, int);
long factorial(int);

int main() {

	time_t  start;

	int n;
	int f;

	cout << "What number in the Fibonacci sequence would you like? " << endl;
	cin >> n;


	cout << "Finding the " << n << "'th " << "fibonacci number...." << endl;
	cout << "Calling Recursive Fibonacci implementation" << endl;

	start = clock();
	FibonacciR fr(n);
	fr.PrintFibonacci();
	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;


	cout << " " << endl;
	cout << "Calling Non-Recursive Fibonacci implementation" << endl;
	start = time(0);
	FibonacciNR fnr(n);
	fnr.PrintFibonacci();
	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	cout << "What n of the factoral would you like: ";
	cin >> f;

	cout << " " << endl;
	cout << "Calling Tail Recursive Factorial Function" << endl;
	start = time(0);
	factorial(f);
	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

	cout << " " << endl;
	cout << "Calling Non Tail Recursive Factorial Function" << endl;
	start = time(0);
	rfactorial(f);
	cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	
	return 0;
}

long rfactorial(int n) //from the instructions, non tail recursive
{
	if (n == 1)
		return 1;
	else
		return  n * rfactorial(n - 1);
}

long factorialHelper(int n, int result) //from the instructions, tail recursive
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

long factorial(int n) //solves for factorial n
{
	return factorialHelper(n, 1);
}