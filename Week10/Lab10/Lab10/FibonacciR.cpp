/*********************************************************************
** Author: Sean Reilly
** Date : June 5, 2015 CS - 162
* * Description : class file....code sourced here : http ://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C first google result for this query, kept same file names
*********************************************************************/

#include "FibonacciR.h"
#include <iostream>


FibonacciR::FibonacciR() { }

FibonacciR::FibonacciR(const int &n) :n_(&n){ }

FibonacciR::~FibonacciR() { }

int FibonacciR::Fibonacci(const int &n) //calc fibonacci number
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciR::PrintFibonacci() //prints fibonacci number
{
	int FibonaciNum = Fibonacci(*n_);
	std::cout << *n_ << "th fibonaci number: " << FibonaciNum << std::endl;
}