#include "stdafx.h"
#include "Product.h"


Product::Product(string name, int power, int value, double durability)
	:Item(name, power, value)
{
	this->durabilty = durability;
}


Product::~Product()
{
}

void Product::decreaseDurability()
{
	this->durabilty -= 0.1;
}

Product* Product::operator+(Product* addProduct) {
	string newName = "Mega" + this->getName();
	int newPower = this->getPower() + addProduct->getPower();
	int newValue = this->getValue() + addProduct->getValue();
	int newDurability = this->durabilty + addProduct->getDurability();
	if (newDurability > 1) newDurability = 1;
	return new Product(newName, newPower, newValue, newDurability);
}

int Product::getWeightedValue() {
	return this->getValue()*durabilty;
}



