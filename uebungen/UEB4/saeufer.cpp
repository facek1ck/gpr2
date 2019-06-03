#include "fighters.h"

Saeufer::Saeufer(const std::string &i_name) : Fighter(i_name)
{
	description = "Has a 50% chance of dodging an attack by tumbling but only hits 50% of his attacks caused by blurry vision, but when he does, he hits with his full body - double damage.";
}

Saeufer::~Saeufer()
{
}

double Saeufer::specialAttack()
{
	return 2.0;
}

double Saeufer::specialDefense()
{
	return 1.0;
}