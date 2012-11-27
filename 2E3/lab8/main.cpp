#include "NPC.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){

	srand(time(0));

	//const int N=10;

	NPC homeNPC,awayNPC;
	//char* homeNPC="Home";
	//char* awayNPC="Away";
	homeNPC.setname("Home");
	awayNPC.setname("Away");
	//int count=0, count1=0;
	//for(int i=0; i<10; i++)

	//{

	awayNPC.defend( homeNPC.attack() );
	awayNPC.print();
	NPC npc1(awayNPC);
	npc1.print();
	NPC npc2;
	npc2 = homeNPC;
	npc2.print();
	//}





	//for(int j=0; j<10; j++)

	//{

	if (awayNPC.IsAlive()){
		//count=count+1;
		homeNPC.defend( awayNPC.attack() );
		homeNPC.print();
		NPC NPC2=homeNPC;
	}
	else cout<<"Home team win!"<<endl;

	cout<<"Away team win!"<<endl;
	//if (homeNPC.IsAlive()){
	//count1=count1+1;
	//}
	//}


	//cout<<"Number of alive for away team is:"<<count<<endl;
	//cout<<"Number of alive for home team is:"<<count1<<endl;


	/*if (count<count1){
	cout<<"Home team win!"<<endl;
	}
	else if (count>count1){
	cout<<"Away team win!"<<endl;
	}
	else cout<<"It's a draw"<<endl;
	*/
	return 0;
}