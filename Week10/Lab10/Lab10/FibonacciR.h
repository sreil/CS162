/*********************************************************************
** Author: Sean Reilly
** Date : June 5, 2015 CS - 162
* * Description : header file....code sourced here : http ://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C first google result for this query, kept same file names
*********************************************************************/

#ifndef FIBONACCIR_H
#define FIBONACCIR_H

class FibonacciR {

public:
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
private:
	FibonacciR();
	int Fibonacci(const int &n);
	const int *n_;
};

#endif