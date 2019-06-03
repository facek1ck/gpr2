// Fighter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#ifndef TESTS
#include <iostream>

#include "fighters.h"

int main()
{
	/*Warrior *myWarri = new Warrior("my first warrior");
    myWarri->showStats();
	myWarri->specialAttack();*/

	Fighter * fighters[10];
	for (int i = 0; i < 10; i++) fighters[i] = nullptr;

	create(fighters);
	create(fighters);

	//view(fighters);

	pick(fighters);
}
#endif