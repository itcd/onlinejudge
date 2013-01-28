#pragma once
#include <string>
#include <iostream>
#include "NPC.h"

using namespace std;

class KingOfNPCs: public NPC{
private:
	int noOfLives;

public:
	KingOfNPCs();
	void print();
	void defend(int attackStrength);
};