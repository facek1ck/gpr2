#ifdef TESTS

#include <iostream>
#include "fighters.h"
#include <gtest/gtest.h>

TEST(FIGHTER, CONSTRUCTOR_WARRIOR)
{
	Fighter* warrior = new Warrior("Warrior");
	ASSERT_EQ(warrior->name, "Warrior");
	delete(warrior);
}

TEST(FIGHTER, CONSTRUCTOR_NINJA)
{
	Fighter* ninja = new Ninja("Ninja");
	ASSERT_EQ(ninja->name, "Ninja");
	delete(ninja);
}

TEST(FIGHTER, INITIALIZE_WARRIOR)
{
	Fighter* warrior = new Warrior("Warrior");
	ASSERT_EQ(warrior->name, "Warrior");
	EXPECT_TRUE(warrior->healthPoints == 100);
	EXPECT_TRUE(warrior->offensePoints > 24 && warrior->offensePoints < 51);
	EXPECT_TRUE(warrior->defensePoints > 24 && warrior->defensePoints < 51);
	EXPECT_FALSE(warrior->description.size() == 0);
	delete(warrior);
}

TEST(FIGHTER, INITIALIZE_NINJA)
{
	Fighter* ninja = new Ninja("Ninja");
	ASSERT_EQ(ninja->name, "Ninja");
	EXPECT_TRUE(ninja->healthPoints == 100);
	EXPECT_TRUE(ninja->offensePoints > 24 && ninja->offensePoints < 51);
	EXPECT_TRUE(ninja->defensePoints > 24 && ninja->defensePoints < 51);
	EXPECT_FALSE(ninja->description.size() == 0);
	delete(ninja);
}

TEST(FIGHTER, SPECIAL_ATTACK_WARRIOR) {
	Fighter* warrior = new Warrior("Warrior");
	EXPECT_TRUE(warrior->specialAttack() == 1 || warrior->specialAttack() == 2);
	delete(warrior);
}

TEST(FIGHTER, SPECIAL_DEFENSE_WARRIOR) {
	Fighter* warrior = new Warrior("Warrior");
	EXPECT_TRUE(warrior->specialDefense() == 1);
	delete(warrior);
}

TEST(FIGHTER, SPECIAL_ATTACK_NINJA) {
	Fighter* ninja = new Ninja("Ninja");
	EXPECT_TRUE(ninja->specialAttack() == 1);
	delete(ninja);
}

TEST(FIGHTER, SPECIAL_DEFENSE_NINJA) {
	Fighter* ninja = new Ninja("Ninja");
	EXPECT_TRUE(ninja->specialDefense() == 0 || ninja->specialDefense() == 1);
	delete(ninja);
}

TEST(FIGHTER, ATTACK) {
	Fighter* warrior = new Warrior("Warrior");
	Fighter* ninja = new Ninja("Ninja");

	warrior->attack(*ninja);

	EXPECT_TRUE(ninja->dead || ninja->healthPoints > 0);
	EXPECT_TRUE(warrior->dead || warrior->healthPoints > 0);
	EXPECT_TRUE(!warrior->dead || !ninja->dead);
	delete(warrior);
	delete(ninja);
}

TEST(FIGHT, FIGHT)
{
	Fighter* fighters[10];
	for (int i = 0; i < 10; i++) fighters[i] = nullptr;

	fighters[0] = new Warrior("Warrior");
	fighters[1] = new Ninja("Ninja");

	fight(fighters, 0, 1);

	EXPECT_TRUE(fighters[0] == nullptr || fighters[1] == nullptr);
	EXPECT_TRUE(fighters[0] == nullptr && fighters[1]->healthPoints > 0 || fighters[1] == nullptr && fighters[0]->healthPoints > 0);

	for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			delete(fighters[i]);
		}
	}
}

TEST(FIGHT, LAST_MAN_STANDING_2_FIGHTERS)
{
	Fighter * fighters[10];
	for (int i = 0; i < 10; i++) fighters[i] = nullptr;

	fighters[0] = new Warrior("Warrior");
	fighters[1] = new Ninja("Ninja");

	lastManStanding(fighters);

	int survivors = 0;

	for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			survivors++;
		}
	}

	ASSERT_EQ(survivors, 1);

	for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			delete(fighters[i]);
		}
	}
}

TEST(FIGHT, LAST_MAN_STANDING_10_FIGHTERS)
{
	Fighter * fighters[10];
	for (int i = 0; i < 10; i++) fighters[i] = nullptr;

	fighters[0] = new Warrior("Warrior1");
	fighters[1] = new Ninja("Ninja1");
	fighters[2] = new Warrior("Warrior2");
	fighters[3] = new Ninja("Ninja2");
	fighters[4] = new Warrior("Warrior3");
	fighters[5] = new Ninja("Ninja3");
	fighters[6] = new Warrior("Warrior4");
	fighters[7] = new Ninja("Ninja4");
	fighters[8] = new Warrior("Warrior5");
	fighters[9] = new Ninja("Ninja5");

	lastManStanding(fighters);

	int survivors = 0;

	for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			survivors++;
		}
	}

	ASSERT_EQ(survivors, 1);

	for (int i = 0; i < 10; i++) {
		if (fighters[i] != nullptr) {
			delete(fighters[i]);
		}
	}
}
/* TODO: FIND WAY TO TEST THIS
TEST(CREATE, CREATE) {
}
*/

/* TODO: FIND WAY TO TEST THIS
TEST(PICK, PICK) {

}
*/

/* TODO: FIND WAY TO TEST THIS
TEST(VIEW, VIEW) {

}
*/

#endif