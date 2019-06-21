#include "stdafx.h"
#include "Item.h"


Item::Item(string name, int power, int value)
{
	this->name = name;
	this->power = power;
	this->value = value;
}


Item::~Item()
{
}
