#pragma once
#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include "item.h"
#include "merchant.h"
class Consumable : public Item
{

private:
	string type;

public:
	Consumable(string name, int power, int value, string type);
	~Consumable();
	void use(Merchant* merchant);
};

#endif

