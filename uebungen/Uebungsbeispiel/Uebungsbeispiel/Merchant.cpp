#include "stdafx.h"
#include "Merchant.h"
#include "Consumable.h";

Merchant::Merchant(string name, int negotiation, Consumable *consumable, Product *product1, Product *product2)
{
    this->name = name;
    this->money = 100;
    this->charisma = 10;
    this->negotiation = 10;
    this->consumable = consumable;
    this->product1 = product1;
    this->product2 = product2;
}

Merchant::~Merchant()
{
}

void Merchant::destroyProdcut(int index)
{
    switch (index)
    {
    case 1:
        free(this->getProduct1());
        this->setProduct1(nullptr);
        break;
    case 2:
        free(this->getProduct2());
        this->setProduct2(nullptr);
        break;
    default:
        throw std::invalid_argument("ERROR: Please enter a valid position! (1,2)");
    }
}

bool Merchant::trade(Merchant *tradingPartner)
{
    if (this->getNegotiation() >= tradingPartner->getCharisma() && tradingPartner->setLiquidity == true)
    {
        int merchantValue = this->getProduct1()->getWeightedValue() + this->getProduct2()->getWeightedValue();
        int partnerValue = tradingPartner->getProduct1()->getWeightedValue() + tradingPartner->getProduct2()->getWeightedValue();
        int diff = merchantValue - partnerValue;

        Product *temp1 = this->getProduct1();
        Product *temp2 = this->getProduct2();
        this->setProduct1(tradingPartner->getProduct1());
        this->setProduct2(tradingPartner->getProduct2());
        tradingPartner->setProduct1(temp1);
        tradingPartner->setProduct2(temp2);
        tradingPartner->getProduct1()->decreaseDurability();
        tradingPartner->getProduct2()->decreaseDurability();
        this->getProduct1()->decreaseDurability();
        this->getProduct2()->decreaseDurability();

        if (tradingPartner->getMoney() - diff < 1)
        {
            this->setMoney(tradingPartner->getMoney());
            tradingPartner->setMoney(0);
            tradingPartner->setLiquidity(false);
            return true;
        }
        else
        {
            this->setMoney(this->getMoney() + diff);
            return true;
        }

        if (this->getProduct1()->getDurability() <= 0)
        {
            this->destroyProdcut(1);
        }
        if (this->getProduct2()->getDurability() <= 0)
        {
            this->destroyProdcut(2);
        }
        if (tradingPartner->getProduct1()->getDurability() <= 0)
        {
            tradingPartner->destroyProdcut(1);
        }
        if (tradingPartner->getProduct2()->getDurability() <= 0)
        {
            tradingPartner->destroyProdcut(2);
        }
    }
    else
    {
        return false;
    }
}

void Merchant::sellItem(int index)
{
    switch (index)
    {
    case 0:
        if (this->getConsumable() != nullptr)
        {
            this->setMoney(this->getMoney() + this->getConsumable()->getValue());
            this->setConsumable(nullptr);
        }
        else
        {
            throw std::invalid_argument("ERROR: You don't have any consumable to sell!")
        }
        break;
    case 1:
        if (this->getProduct1() != nullptr)
        {
            this->setMoney(this->getMoney() + this->getProduct1()->getWeightedValue());
            this->setProduct1(nullptr);
        }
        else
        {
            throw std::invalid_argument("ERROR: You don't have any item in that slot!")
        }
        break;
    case 2:
        if (this->getProduct2() != nullptr)
        {
            this->setMoney(this->getMoney() + this->getProduct1()->getWeightedValue());
            this->setProduct2(nullptr);
        }
        else
        {
            throw std::invalid_argument("ERROR: You don't have any item in that slot!")
        }
        break;
    default:
        throw std::invalid_argument("ERROR: Please enter a valid position! (0,1,2)");
    }
}
