#include "MP3.h"
#include "MP3Database.h"
#include <string>
#include <iostream>

using namespace std;

MP3Database::MP3Database (int size){
	list=new MP3[size];
}

MP3Database::~MP3Database (){
	delete[] list;
}

void MP3Database::print(){
	MP3 *p = list;
    for(int i=0; i<size; i++)
    {
        p->print();
        p++;
    }

	
	//for (int i=0;i<size;i++){
		//list[i].MP3::print();
	//}
}

void MP3Database::search(string artname){

	MP3 *p=list;
	int count=0;
	for (int i=0;i<size;i++){
		if (p->getartname().compare(artname)==0){
			//cout <<"Artist is found."<<endl;
			p->print();
			count++;
			
		}
	}	
		if (count==0){
			cout<<"Artist is not found."<<endl;
		}
}	

	