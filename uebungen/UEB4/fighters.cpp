#include "fighters.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

int FIGHTERS_ARRAY_LENGTH = 10;

Fighter::Fighter(const string& name) {
    this->name = name;
    this->offensePoints = 25 + (rand() % 26);
    this->defensePoints = 25 + (rand() % 26);
}

void Fighter::attack(Fighter& opponent) {
    int hitpointsAttacker = rand() % (this->offensePoints + 1);
    int specialAttackMultiplicator1 = this->specialAttack();
    hitpointsAttacker = (int) (((double) hitpointsAttacker) * (specialAttackMultiplicator1==-1?2:specialAttackMultiplicator1));
    if(opponent.specialDefense() == 0) {
        hitpointsAttacker = 0;
    }
    cout << this->name << " dealt " << hitpointsAttacker << " damage to " << opponent.name << " in an attack" << endl;

    if(opponent.healthPoints <= 0) {
        opponent.dead = true;
        cout << "-->" << opponent.name << " died" << endl;
    } else {
        cout << "-->" << opponent.name << " has " << opponent.healthPoints << " hp left" << endl;
        int hitpointsDefender = rand() % (opponent.defensePoints + 1);
        int specialAttackMultiplicator = opponent.specialAttack();
        hitpointsDefender = (int) (((double) hitpointsDefender) * (specialAttackMultiplicator == 0 ? 1 : (specialAttackMultiplicator == -1 ? 2:specialAttackMultiplicator)));
        this->healthPoints -= hitpointsDefender;
        cout << "-" << opponent.name << " countered " << hitpointsDefender << " damage to " << this->name << " with his defense" << endl;

        if(this->healthPoints <= 0) {
            this->dead = true;
            cout << this->name << " died" << endl;
        } else {
            cout << "-->" << this->name << " has " << this->healthPoints << " hp left\n" << endl;
        }
    }
}

// Print stats
const void Fighter::showStats() {
    cout << this->name << " (" << this->description << ")" << endl;
    cout << "Offense points: " << this->offensePoints << ", Defense points: " << this->defensePoints << endl;
}

// Warrior
Warrior::Warrior(const string& name) : Fighter::Fighter(name) {
    this->description = "He has the chance of hitting with double damage (1/6 chance).";
}

double Warrior::specialAttack() {
    int probability = (rand() % 6) + 1;
    if(probability == 1) {
        return 1;
    } else {
        return 2;
    }
}

double Warrior::specialDefense() {
    return 1;
}

// Ninja
Ninja::Ninja(const string& name) : Fighter::Fighter(name) {
    this->description = "Ninjas can dodge Attacks by moving very fast (1/6 chance).";
}

double Ninja::specialAttack() {
    return 1;
}

double Ninja::specialDefense() {
    int probability = (rand() % 6) + 1;
    if(probability == 1) {
        return 0;
    } else {
        return 1;
    }
}

// Säufer
Saeufer::Saeufer(const string& name) : Fighter::Fighter(name) {
    this->description = "Hits only half of his attacks (1/2 chance), when he does he hits with double damage. Also he has a 50% chance of dodging attacks by tumbling away.";
}

double Saeufer::specialAttack() {
    int probability = rand() % 2;
    if(probability == 1) {
        return 2;
    } else {
        return 0;
    }
}

double Saeufer::specialDefense() {
    int probability = rand()%2;
    if(probability == 1) {
        return 2;
    } else {
        return 0;
    }
}

// Faule Sau
FauleSau::FauleSau(const string& name) : Fighter::Fighter(name) {
    this->description = "Doesn't do shit unless he needs to. Doesnt defend or attack until his HP are below 15. Then he hits with fatal damage.";
}

double FauleSau::specialAttack() {
    if (this->healthPoints <=15){
        return 100;
    } else {
        return -1;
    }
}

double FauleSau::specialDefense() {
        return 1;
}

void create(Fighter* fightersArray[]) {
    int firstFreeIndex = -1;
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] == nullptr) {
            firstFreeIndex = i;
            break;
        }
    }

    if(firstFreeIndex > -1) {
        cout << "There are 4 different types of fighters:" << endl;
        cout << "Warrior, Ninja, Saeufer, Faule Sau" << endl;
        cout << "Which type of fighter do you want to create?" << endl;
        cout << "-1 Warrior" << endl << "-2 Ninja" << endl << "-3 Saeufer" << endl << "-4 Faule Sau" << endl;

CHOOSE_FIGHTER:
        int type = 0;
        cin >> type;

        if(cin.fail() || type < 1 || type > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Try again (1, 2, 3, 4)" << endl;
            goto CHOOSE_FIGHTER;
        } else {
            string name = "";
            cout << "Now choose a name for your fighter" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);

            switch(type) {
            case 1:
                fightersArray[firstFreeIndex] = new Warrior(name);
                break;
            case 2:
                fightersArray[firstFreeIndex] = new Ninja(name);
                break;
            case 3:
                fightersArray[firstFreeIndex] = new Saeufer(name);
                break;
            case 4:
                fightersArray[firstFreeIndex] = new FauleSau(name);
                break;
            }

            cout << "Your fighter \"" << name << "\" was successfully created at index " << firstFreeIndex << endl;
        }
    } else {
        cout << "The array is full, you can't add any more fighters" << endl;
    }
}

void deleteFighter(Fighter* fightersArray[]) {
    int countFighters = 0;
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] != nullptr) {
            countFighters++;
        }
    }
    if(countFighters < 1) {
        cout << "There are no fighters to delete" << endl;
        return;
    }

    view(fightersArray);

PICK:
    int pick = -1;
    cout << "Pick fighter to delete by index:" << endl;
    cin >> pick;
    if(cin.fail() || fightersArray[pick] == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again" << endl;
        goto PICK;
    }

    delete fightersArray[pick];
    fightersArray[pick] = nullptr;
}

void fight(Fighter* fightersArray[], int index1, int index2) {
    if(fightersArray[index1] != nullptr && fightersArray[index2] != nullptr) {
        cout << "### This fight is \"" << fightersArray[index1]->name << "\" against \"" + fightersArray[index2]->name << "\" ###" << endl;

        int order = 0;
        while(fightersArray[index1]->dead == false && fightersArray[index2]->dead == false) {
            order % 2 == 0 ? fightersArray[index1]->attack(*fightersArray[index2]) : fightersArray[index2]->attack(*fightersArray[index1]);
            order++;
        }

        if(fightersArray[index1]->dead) {
            delete fightersArray[index1];
            fightersArray[index1] = nullptr;
        }
        if(fightersArray[index2]->dead) {
            delete fightersArray[index2];
            fightersArray[index2] = nullptr;
        }

        cout <<"\n" << "### The winner is \"" << (fightersArray[index1] != nullptr ? fightersArray[index1]->name : fightersArray[index2]->name) << "\" ###" << endl;
    }
}

void pick(Fighter* fightersArray []) {
    int countFighters = 0;
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] != nullptr) {
            countFighters++;
        }
    }
    if(countFighters < 2) {
        cout << "You need at least 2 fighters for a fight" << endl;
        return;
    }

    cout << "Choose 2 fighters that fights against each other until one dies" << endl;
    view(fightersArray);

PICK:
    int pickOne = -1;
    int pickTwo = -1;
    cout << "Pick attacker by index:" << endl;
    cin >> pickOne;
    if(cin.fail() || fightersArray[pickOne] == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again" << endl;
        goto PICK;
    }
    cout << "Pick defender by index:" << endl;
    cin >> pickTwo;
    if(cin.fail() || fightersArray[pickTwo] == nullptr) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again" << endl;
        goto PICK;
    }

    fight(fightersArray, pickOne, pickTwo);
}

void lastManStanding(Fighter* fightersArray[]) {
    int countFighters = 0;
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] != nullptr) {
            countFighters++;
        }
    }
    if(countFighters < 2) {
        cout << "You need at least 2 fighters for a fight" << endl;
        return;
    }

START_FIGHT:
    int randAttackerIndex = rand() % FIGHTERS_ARRAY_LENGTH;
    while(fightersArray[randAttackerIndex] == nullptr) {
        randAttackerIndex = rand() % FIGHTERS_ARRAY_LENGTH;
    }
    cout << "Attacker at " << randAttackerIndex << endl;

    int randDefenderIndex = rand() % FIGHTERS_ARRAY_LENGTH;
    while(fightersArray[randDefenderIndex] == nullptr || randDefenderIndex == randAttackerIndex) {
        randDefenderIndex = rand() % FIGHTERS_ARRAY_LENGTH;
    }
    cout << "Defender at " << randDefenderIndex << endl;

    fight(fightersArray, randAttackerIndex, randDefenderIndex);

    int survivors = 0;
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] != nullptr) {
            survivors++;
        }
    }

    if(survivors > 1)
        goto START_FIGHT;
}

void view(Fighter* fightersArray[]) {
    for (int i = 0; i < FIGHTERS_ARRAY_LENGTH; i++) {
        if (fightersArray[i] != nullptr) {
            cout << "-" << i << "\t" << viewIndividual(fightersArray[i]) << endl;
        }
    }
}

string viewIndividual(Fighter* fighterPtr) {
    string out_string;
    stringstream ss;
    ss << fighterPtr->name << "\t(" << fighterPtr->getHealthPoints() << "hp, " << fighterPtr->getOffensePoints() << "op, " << fighterPtr->getDefensePoints() << "dp)" << "\t(" << fighterPtr->getDescription() << ")";
    out_string = ss.str();

    return out_string;
}
