#include "NPC.h"
#include <iostream>
#include <ctime>

using namespace std;


NPC::NPC(){

	strength=rand()%20 + 1;

	skill = rand()%5 + 1;

	Alive = true;
	name= new char;
	*name =0;
	length=0;

}
NPC::~NPC(){
	delete []name;
}
char* NPC::getname(){
	char *Name=new char[length+1];
	for (int i=0;i<length+1;i++){
		Name[i]=name[i];
		return Name;
	}
}
void NPC::setname(char *Name){
	int i;
	for(i=0;Name[i]!=0;i++);
	length=i;
	name=new char[length+1];
	for(i=0;i<length+1;i++){
		name[i]=Name[i];
	}
}

NPC::NPC(const NPC & New)
	:strength(New.strength),skill(New.skill),length(New.length),Alive(New.Alive){
		name=new char[length+1];
		for(int i=0;i<length+1;i++){
			name[i]=New.name[i];
		}
		cout<<"copy using copy construtor"<<endl;
}

void NPC::operator=(const NPC &New){
	strength=New.strength;
	skill=New.skill;
	length=New.length;
	Alive=New.Alive;
	delete [] name;
	name=new char[length+1];
	for(int i=0;i<length+1;i++){
		name[i]=New.name[i];
	}
	cout<<"assigned using assignment operator"<<endl;

}


//NPC::NPC(int str, int ski, bool alive){
//	strength=str;
//	skill=ski;
//	Alive=alive;
//}

bool NPC::IsAlive(){

	return Alive;

}


void NPC::print(){

	cout << "strength: "<<strength<<endl;
	cout << "skill: "<<skill<<endl;
	cout << "alive: "<< Alive<<endl;
	cout <<" Name: "<<name<<endl;
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
		if (strength<=0){
			Alive=false;
		}
	}



}
