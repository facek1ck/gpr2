#include <iostream>

#include "fighters.h"
#include "randomRange.h"

using namespace std;

#define FIGHT_COUNT 10

Fighter::Fighter(const std::string &name)
{
	this->name = name;
	this->healthPoints = 100;
	this->offensePoints = Random::Range(25, 50);
	this->defensePoints = Random::Range(25, 50);
}

void Fighter::attack(Fighter &enemy)
{
	int atk = Random::Range(0, offensePoints);
	if (Random::Range(1, 6) == 1) // special Attack
	{
		atk *= (int)specialAttack();
	}

	// case ninja takes no damage
	if (Random::Range(1, 6) == 1) // special Defense
	{
		atk *= (int)enemy.specialDefense();
	}

	enemy.healthPoints -= atk;
	if (enemy.healthPoints < 1) // enemy fighter died
	{
		enemy.dead = true;
	}
	else
	{
		// enemy is still alive -> able to counterattack
		atk = Random::Range(0, enemy.defensePoints);
		healthPoints -= atk;
	}
}

const void Fighter::showStats()
{
	std::cout << "name: " << name << std::endl;
	std::cout << "desc: " << description << std::endl;
	std::cout << "health: " << healthPoints << std::endl;
	std::cout << "offensePoints: " << offensePoints << std::endl;
	std::cout << "defensePoints: " << defensePoints << std::endl;
}

void create(Fighter *fighters[])
{
	cout << "enter type: " << endl;
	cout << "[1] Warrior" << endl;
	cout << "[2] Faule Sau" << endl;
	cout << "[3] Ninja" << endl;
	cout << "[4] Säufer" << endl;

	int type = 0;
	while (type < 1 || type > 4)
	{
		cin >> type;
	}

	std::string name = "";
	cout << "name your fighter: " << endl;
	cin >> name;

	Fighter *fighter = nullptr;
	switch (type)
	{
	case 1:
		fighter = new Warrior(name);
		break;
	case 2:
		fighter = new FauleSau(name);
		break;
	case 3:
		fighter = new Ninja(name);
		break;
	case 4:
		fighter = new Saeufer(name);
		break;
	}

	for (int idx = 0; idx < FIGHT_COUNT; ++idx)
	{
		if (fighters[idx] == nullptr)
		{
			fighters[idx] = fighter;
			break;
		}
	}
}

void fight(Fighter *fighters[], int first, int second)
{
	Fighter *attacker = fighters[first];
	Fighter *defender = fighters[second];

	while (attacker->dead != true)
	{
		attacker->attack(*defender);
		if (attacker->dead) // attacker can die because of counterattack
		{
			break;
		}

		//attacker->showStats();
		std::swap(attacker, defender);
	}

	// delete dead fighter
	// we need to find the fighter who died in our array:
	// it could be either the defending fighter or the attacking one
	// but it is definitely "attacker" due to above code
	int idxFighter = -1;
	for (int idx = 0; idx < FIGHT_COUNT; ++idx)
	{
		if (fighters[idx] == attacker)
		{
			idxFighter = idx;
			break;
		}
	}

	if (idxFighter > -1) // else something went wrong
	{
		delete fighters[idxFighter];
		fighters[idxFighter] = nullptr;
	}
}

void pick(Fighter *fighters[])
{
	view(fighters);

	int selected1 = -1, selected2 = -1;
	std::string selectedName = "";
	while (selected1 == -1 || selected2 == -1)
	{
		std::cout << "Select " << ((selected1 == -1) ? "first" : "second") << " fighter: " << std::endl;
		cin >> selectedName;

		for (int idx = 0; idx < FIGHT_COUNT; ++idx)
		{
			Fighter *fighter = fighters[idx];
			if (fighters[idx] != nullptr && fighters[idx]->name == selectedName)
			{
				//(selected1 == -1) ? selected1 = idx : selected2 = idx;
				((selected1 == -1) ? selected1 : selected2) = idx;
				break;
			}
		}

		if (selected1 != - 1 && selected1 == selected2)
		{
			cout << fighters[selected1]->name << " won't fight against himself" << endl;
			selected2 = -1;
		}
	}

	fight(fighters, selected1, selected2);
}

void lastManStanding(Fighter *fighters[])
{
	vector<int> availableFighters;
	do
	{
		availableFighters.clear();
		for (int idx_fighter = 0; idx_fighter < FIGHT_COUNT; ++idx_fighter)
		{
			if (fighters[idx_fighter] != nullptr)
			{
				availableFighters.push_back(idx_fighter);
			}
		}

		// needed to pick at least 2 fighters
		int pick1 = Random::Range(0, availableFighters.size() - 1);
		int pick2 = pick1;
		do
		{
			pick2 = Random::Range(0, availableFighters.size() - 1);
		} while (pick1 == pick2);

		fight(fighters, availableFighters[pick1], availableFighters.at(pick2));
	} while (availableFighters.size() > 2);
}

void view(Fighter *fighters[])
{
	for (int idx = 0; idx < FIGHT_COUNT; ++idx)
	{
		if (fighters[idx] != nullptr)
		{
			fighters[idx]->showStats();
		}
	}
}