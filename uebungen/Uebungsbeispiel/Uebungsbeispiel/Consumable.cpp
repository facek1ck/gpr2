#include "stdafx.h"
#include "consumable.h"

Consumable::Consumable(string name, int power, int value, string type)
	:Item(name, power, value)
{
	this->type = type;
}


Consumable::~Consumable()
{
}


void Consumable::use(Merchant* merchant)
{
	if (this->type == "TYPE_CH_LESSON") {
		int currentCharisma = merchant->getCharisma();
		merchant->setCharisma(currentCharisma + 1);
	}
	else if (this->type == "TYPE_NG_LESSON") {
		int currentNegotiation = merchant->getNegotiation();
		merchant->setCharisma(currentNegotiation + 1);
	}
}
