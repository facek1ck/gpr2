#ifdef TESTS

#include <iostream>
#include "postfix.h"
#include <gtest/gtest.h>

TEST(ADD, ADD_TWO_POSITIVE_NUMBERS)
{
	std::istringstream input = std::istringstream("1 1 + =");
	ASSERT_EQ(getResult(input), 2);
}

TEST(SUBSTRACT, SUBSTRACT_TWO_POSITIVE_NUMBERS)
{
	std::istringstream input = std::istringstream("10 2 - =");
	ASSERT_EQ(getResult(input), 8);
}

TEST(MULTIPLY, MULTIPLY_TWO_POSITIVE_NUMBERS)
{
	std::istringstream input = std::istringstream("8 2 * =");
	ASSERT_EQ(getResult(input), 16);
}

TEST(DIVIDE, DIVIDE_TWO_POSITIVE_NUMBERS)
{
	std::istringstream input = std::istringstream("27 3 / =");
	ASSERT_EQ(getResult(input), 9);
}

TEST(MODULO, MODULO_TWO_POSITIVE_NUMBERS)
{
	std::istringstream input = std::istringstream("14 4 % =");
	ASSERT_EQ(getResult(input), 2);
}

TEST(MIXED, LONG_OP)
{
	std::istringstream input = std::istringstream("14 4 + 2 * 4 / 3 - 4 % =");
	ASSERT_EQ(getResult(input), 2);
}

TEST(MIXED, PRECEDENCE)
{
	std::istringstream input = std::istringstream("5 3 - 2 4 + * =");
	ASSERT_EQ(getResult(input), 12);
}

#endif