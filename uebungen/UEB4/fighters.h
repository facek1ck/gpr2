#include <string>
#ifndef FIGHTERS_H_include
#define FIGHTERS_H

class Fighter {

#ifdef TESTS
public:
#else
protected:
#endif
    int healthPoints = 100;
    int offensePoints;
    int defensePoints;
    std::string description;
public:
    bool dead = false;
    std::string name;
    Fighter(const std::string&);
    virtual ~Fighter() {};
    virtual double specialAttack() = 0;
    virtual double specialDefense() = 0;    
    void attack(Fighter&);
    const void showStats();

    int getHealthPoints() { return healthPoints; };
    int getOffensePoints() { return offensePoints; };
    int getDefensePoints() { return defensePoints; };;
    std::string getDescription() { return description; };;
};

class Warrior : public Fighter {
public:
    Warrior(const std::string&);
    virtual ~Warrior() {};
    double specialAttack();
    double specialDefense();
};

class Ninja : public Fighter {
public:
    Ninja(const std::string&);
    virtual ~Ninja() {};
    double specialAttack();
    double specialDefense();
};

class Saeufer : public Fighter {
public:
    Saeufer(const std::string&);
    virtual ~Saeufer() {};
    double specialAttack();
    double specialDefense();
};

class FauleSau : public Fighter {
public:
    FauleSau(const std::string&);
    virtual ~FauleSau() {};
    double specialAttack();
    double specialDefense();
};

void create(Fighter*[]);
void deleteFighter(Fighter*[]);
void fight(Fighter *[], int, int);
void pick(Fighter *[]);
void lastManStanding(Fighter*[]);
void view(Fighter*[]);

std::string viewIndividual(Fighter* fighterPtr);
#endif
