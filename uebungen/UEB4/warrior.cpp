#include "fighters.h"

Warrior::Warrior(const std::string &name) : Fighter(name)
{
	description = "Warrior. The warrior is a brave fighter that sometimes can attack very strongly (one by six chance of double hitpoints).";
}

Warrior::~Warrior()
{

}

double Warrior::specialAttack()
{
	return 2.0;
}

double Warrior::specialDefense()
{
	return 1.0;
}