#include "lab3.h"
#include <iostream>
#include <ctime>

using namespace std;


bool NPC::IsAlive(){
	return Alive;
}


void NPC::print(){
	cout << "strength "<<strength<<endl;
	cout << "skill"<<skill<<endl;
	cout << "alive"<< Alive<<endl;
}

int NPC::attack(){
	int roll = rand()%6+1;
	int result= skill*roll;
	return result;
}

void NPC::defend(int attackStrength){
	int roll = rand()%6+1;
	int result= skill*roll;
	int strofatt=attackStrength-result;

	if (strofatt>0){
		strength=strength-strofatt;
	}
	else if (strofatt<0){
		strength=0;
	}
	else Alive=false;
}
