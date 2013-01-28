#include "lab3.h"
#include <iostream>
#include <ctime>
#include "KingOfNPCs.h"

using namespace std;

void KingOfNPCs::print(){
	cout<<"Number of lives:"<<noOfLives<<endl;
	NPC::print();
}



KingOfNPCs::KingOfNPCs(){
	NPC::setstrength(int(rand()%50+1));
	NPC::setskill(int(rand()%5+1));
	noOfLives=rand()%3+1;
}


void KingOfNPCs::defend(int attackStrength){
	int roll = rand()%6+1;
	int result= getskill()*roll;
	int strofatt=attackStrength-result;

	if (strofatt>0){
		setstrength(getstrength()-strofatt);
	}
	if (strofatt<=0){
		noOfLives=noOfLives-1;
		setstrength(int(rand()%50+1));
		if (noOfLives==0){
			setalive(false);
		}
	}
