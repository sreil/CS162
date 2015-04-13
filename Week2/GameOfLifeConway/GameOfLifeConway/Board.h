/*********************************************************************
** Author: Sean Reilly
** Date: April 11, 2015 CS-162
** Description: Conway's Game of Life - header for menu options
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

class Board
{
private:
	char board[50][50];
	char tempBoard[50][50];
public:
	Board();
	void print();
	void temporary();
	void temporaryConvert();
	void runSim();
	void glider();
	void gliderGun();
	void oscillator();
	void input();
};
#endif