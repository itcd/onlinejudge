#include "NPC.h"
#include <iostream>
#include <ctime>
#include "KingOfNPCs.h"

using namespace std;

int main(){
	srand(time(0)); 
	const int N=100;
	NPC NPC[N];
	KingOfNPCs King;

	for(int i=0; i<100; i++)

	{

		NPC[i].defend(King.attack() );
		NPC[i].print();
	}

	King.NPC::defend(1);

	return 0;
}