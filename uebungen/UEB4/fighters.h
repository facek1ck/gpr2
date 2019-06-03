#include<string>
#ifndef FIGHTERS_H_include
#define FIGHTERS_H_include

class Fighter
{
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
	Fighter(const std::string &);
    virtual ~Fighter(){};
    
    void attack(Fighter&);
    const void showStats();

#ifdef TESTS
	public:
#else
	protected:
#endif
	virtual double specialAttack() = 0;
	virtual double specialDefense() = 0;
};

class Saeufer : public Fighter
{
public:
	Saeufer(const std::string&);
	virtual ~Saeufer();
	double specialAttack();
	double specialDefense();
};

class FauleSau : public Fighter
{
public:
	FauleSau(const std::string&);
	virtual ~FauleSau();
	double specialAttack();
	double specialDefense();
};

class Ninja : public Fighter
{
public:
	Ninja();
	Ninja(const std::string&);
	virtual ~Ninja();
	double specialAttack();
	double specialDefense();
};

class Warrior : public Fighter
{
public:
	Warrior(const std::string&);
	virtual ~Warrior();
	double specialAttack();
	double specialDefense();
};

void create(Fighter*[]);
void fight(Fighter *[], int, int);
void pick(Fighter *[]);
void lastManStanding(Fighter*[]);
void view(Fighter*[]);
#endif // FIGHTERS_H_include
