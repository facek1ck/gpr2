#include "fighters.h"

Ninja::Ninja(const std::string &i_name) : Fighter(i_name)
{
	description = "Ninjas move very fast, hence they can escape attacks sometimes but still launch a counterattack(one by six chance that an attack does not cause any damage)";
}

Ninja::~Ninja()
{
}

double Ninja::specialAttack()
{
	return 1.0;
}

double Ninja::specialDefense()
{
	return 0.0;
}