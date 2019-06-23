#pragma once
#include "item.h"

class Product : public Item
{

private:
	double durabilty;

public:
	Product(string name, int power, int value, double durability);
	~Product();
	void setDurability(double durability)
	{
		this->durabilty = durability;
	}

	double getDurability()
	{
		return this->durabilty;
	};
	void decreaseDurability();
	Product *operator+(Product *addProducts);
	int getWeightedValue();
};
