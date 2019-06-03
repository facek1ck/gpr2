#pragma once

#ifndef RANDOMRANGE_H_include
#define RANDOMRANGE_H_include

#include <random>
#include <ctime> // -- for time

class Random
{
public:
	static int Range(int min, int max)
	{
		// seeding for the first time only!
		static bool init = false;
		if (init == false)
		{
			srand((unsigned int)time(NULL));
			init = true;
		}
		return min + rand() % (max - min + 1);
	}

private:
	// Disallow creating an instance of this object
	Random() {};
};
#endif // RANDOMRANGE_H_include