#include "fighters.h"

FauleSau::FauleSau(const std::string &i_name) : Fighter(i_name)
{
	description = "Is too lazy to attack most of the times. Attacks only if needed - so when his HP are below 10. But then he cause fatal damage!";
}

FauleSau::~FauleSau()
{
}

double FauleSau::specialAttack()
{
	return 100.0;
}

double FauleSau::specialDefense()
{
	return 1.0;
}