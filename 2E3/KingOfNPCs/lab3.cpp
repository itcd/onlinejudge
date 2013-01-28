//
// 2e3 lab3
// (c) 2010 Trinity College Dublin
//

#include "NPC.h"
#include "KingOfNPCs.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	//seed the random number generator
	srand(time(0));

	KingOfNPCs k;
	NPC attackers[100];
	int noOfAttacks=0;
	int noOfDeadEnemies=0;

	for(int i=0; i<100; i++)
	{
		if (k.isAlive())
		{
			k.defend( attackers[i].attack() );
			k.print();
			noOfAttacks++;
			attackers[i].defend(k.attack());

			if (!attackers[i].isAlive())
				noOfDeadEnemies++;

		}
		else
			break;
	}

	cout << "It took " << noOfAttacks << " enemy NPCs to kill the king" <<endl;
	cout << "King killed " << noOfDeadEnemies << " enemies" <<endl;

	/*

	// declare 2 arrays of NPC teams
	NPC homeNPCs[10];
	NPC awayNPCs[10];

	// Print out the starting stats of all characters...
	cout << "Stats for the home team: "<<endl;
	for(int i=0; i<10; i++)
	{
		cout << "Character #" << i << endl;
		homeNPCs[i].print();
	}

	cout << "Stats for the away team: "<<endl;
	for(int j=0; j<10; j++)
	{
		cout << "Character #" << j << endl;
		awayNPCs[j].print();
	}

	//allow home team to attack
	 for(int i=0; i<10; i++)
	{
		awayNPCs[i].defend( homeNPCs[i].attack() );
	 }

	 //allow the away team to attack, first checking if away NPC survived previous attack
	 for(int j=0; j<10; j++)
	{
		if (awayNPCs[j].isAlive())
			homeNPCs[j].defend( awayNPCs[j].attack() );
	 }

	 //count how many casualties on each time
	 int homeDead =0;
	 int awayDead = 0;
	

	for(int i=0; i<10; i++)
	{
		if (!homeNPCs[i].isAlive())
			homeDead++;
		if (!awayNPCs[i].isAlive())
			awayDead++;
   }

	cout << "Number of dead players on the home team is: "<< homeDead<<endl;
	cout << "Number of dead players on the away team is: "<< awayDead<<endl;

	if (homeDead==awayDead)
		cout <<"This fight ended in a draw" <<endl;
	else if (homeDead>awayDead)
		cout <<"Home team won this fight" <<endl;
	else 
		cout <<"Away team won this fight" <<endl;

	*/
}
