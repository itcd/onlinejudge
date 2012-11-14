#include "MP3.h"
#include "MP3Database.h"
#include <string>
#include <iostream>

using namespace std;

int main(){

	int s,dur,year;
	string sname,aname,rev;
	cout<<"Enter size of mp3 collection: "<<endl;
	cin>> s;

	MP3Database data(s);
	MP3 *p = data.list;
	for (int i=0;i<s;i++,p++){
		cin.ignore(INT_MAX, '\n');
		cout << "Song Name: "; 
		getline(cin, sname);
		cout <<"Artist Name:";
		getline(cin,aname);
		cout<<"Short review:";
		getline(cin,rev);
		cout<<"Enter durtion (sec):";
		cin>>dur;
		cout<<"Enter year realse: ";
		cin>>year;
		(*p) = MP3(sname, aname, rev, dur, year);
	}
		
	cout<<endl<<"Here is the list"<<endl;
	p = data.list;
	for (int i=0;i<s;i++,p++){
		p->print();
		cout<<endl;
	}
	
	return 0;
}
