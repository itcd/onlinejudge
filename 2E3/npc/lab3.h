#include <string>
#include <iostream>

using namespace std;

class NPC {
public:
	int strength,skill;
	bool Alive;

	bool IsAlive();
	void print();
	int attack();
	void defend(int attackStrength);

};
