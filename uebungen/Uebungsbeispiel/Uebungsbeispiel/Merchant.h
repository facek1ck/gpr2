#pragma once
#ifndef MERCHANT_H
#define MERCHANT_H
using namespace std;
#include <string>

class Consumable;
class Product;

class Merchant
{

private:
	string name;
	bool liquidity;
	int money;
	int charisma;
	int negotiation;
	Consumable* consumable;
	Product* product1;
	Product* product2;

public:
	Merchant(string name, Consumable *consumable, Product *product1, Product *product2);
	~Merchant();
	void destroyProdcut(int index);
	bool trade(Merchant *tradingPartner);
	void sellItem(int index);
	void printStatus();

	string getName()
	{
		return this->name;
	}

	void setLiquidity(bool liquidity)
	{
		this->liquidity = liquidity;
	}

	bool getLiquidity()
	{
		return this->liquidity;
	}

	void setMoney(int money)
	{
		this->money = money;
	}

	int getMoney()
	{
		return this->money;
	}

	void setCharisma(int charisma)
	{
		this->charisma = charisma;
	}

	int getCharisma()
	{
		return this->charisma;
	}

	void setNegotiation(int negotiation)
	{
		this->negotiation = negotiation;
	}

	int getNegotiation()
	{
		return this->negotiation;
	}

	void setConsumable(Consumable *consumable)
	{
		this->consumable = consumable;
	}

	Consumable *getConsumable()
	{
		return this->consumable;
	}

	void setProduct1(Product *product)
	{
		this->product1 = product;
	}

	Product *getProduct1()
	{
		return this->product1;
	}

	void setProduct2(Product *product)
	{
		this->product2 = product;
	}

	Product *getProduct2()
	{
		return this->product2;
	}
};

#endif