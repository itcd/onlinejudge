
#include <iostream>
using namespace std;

class NPC {

private:
	char *name;
public:

	int strength,skill;
	int length;
	bool Alive;

	NPC();
	~NPC();
	//NPC(int str, int ski, bool alive);
	NPC (const NPC & New);
	void operator =(const NPC & New);
	char* getname();
	void setname(char *Name);
	bool IsAlive();

	void print();

	int attack();

	void defend(int attackStrength);




};