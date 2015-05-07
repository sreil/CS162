/*********************************************************************
** Author: Sean Reilly
** Date: April 23, 2015 CS-162
** Description: item.cpp 
*********************************************************************/

#include "Item.h"
#include <cmath>

using namespace std;

//Default Constructor
Item::Item()
{
	name = "";
	price = 0.0;
	quanity = 0;
	subTotal = 0.0;
}

Item::Item(string newName, int newQuanity, double newPrice, string  newUnit)
{
	name = newName;
	quanity = newQuanity;
	price = newPrice;
	unit = newUnit;
	subTotal = quanity * price;
}

string Item::getName()
{
	return name;
}

int Item::getQty()
{
	return quanity;
}

double Item::getPrice()
{
	return price;
}

string Item::getUnit()
{
	return unit;
}

double Item::getSubTotal()
{
	return subTotal;
}

void Item::setName(string newName)
{
	name = newName;
}

void Item::setPrice(double newPrice)
{
	price = newPrice;
}

void Item::setQty(int newQuanity)
{
	quanity = newQuanity;
}

void Item::setUnit(string uType)
{
	unit = uType;
}

void Item::setValues(string newName, int newQuanity, double newPrice, string newUnit)
{
	name = newName;
	quanity = newQuanity;
	price = newPrice;
	unit = newUnit;
	subTotal = quanity * price;
}

//Constructor
ClubItem::ClubItem()
{
	salePrice = price;
}

void ClubItem::salesCheck(bool)
{
	salePrice = price * 0.9;
	setPrice(salePrice);
	subTotal = quanity * price;

}