#pragma once
#include "item.h"
#include "merchant.h";
class Consumable : Item
{

private:
	string type;

public:
	Consumable(string name, int power, int value, string type);
	~Consumable();
	void use(Merchant* merchant);
};

