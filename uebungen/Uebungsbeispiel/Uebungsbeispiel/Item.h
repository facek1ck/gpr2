#include <string>
using namespace std;
class Item
{
private:
	string name;
	int power;
	int value;

public:
	Item(string name, int power, int value);
	~Item();

	string getName() {
		return name;
	}

	int getPower() {
		return power;
	}

	int getValue() {
		return value;
	}
};