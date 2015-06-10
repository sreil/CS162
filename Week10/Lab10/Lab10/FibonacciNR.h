/*********************************************************************
** Author: Sean Reilly
** Date : June 5, 2015 CS - 162
* * Description : header file, non recursive aspect....code sourced here : http ://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C first google result for this query, kept same file names
*********************************************************************/

#ifndef FIBONACCINR_H
#define FIBONACCINR_H

class FibonacciNR {
public:
	FibonacciNR(const int &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();
private:
	FibonacciNR();
	int Fibonacci(const int &n);
	const int* n_;
};
#endif