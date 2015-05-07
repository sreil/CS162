/*********************************************************************
** Author: Sean Reilly
** Date: April 23, 2015 CS-162
** Description: header for item.cpp
*********************************************************************/

#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item {

protected:
	string name;
	int quanity;
	string unit;
	double price;
	double subTotal;

public:
	Item();
	Item(string, int, double, string);

	string getName();
	int getQty();
	double getPrice();
	string getUnit();
	double getSubTotal();

	void setName(string);
	void setQty(int);
	void setPrice(double);
	void setUnit(string);
	void setValues(string, int, double, string);

};

class ClubItem : public Item
{
private:
	bool clubItem;
	double salePrice;
public:
	ClubItem();
	void salesCheck(bool);
};

#endif