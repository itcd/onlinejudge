#include "MP3.h"
#include <iostream>
#include <string>

using namespace std;

MP3::MP3(){
	songname= "";
	artname="";
	review="";
	duration=0;
	year=0;
}

void MP3::print(){
	cout << "Song name: "<<songname<<endl;
	cout << "Artist name: "<<artname<<endl;
	cout << "Song duration (sec): "<<duration<<endl;
	cout << "Short review: "<<review<<endl;
	cout << "Year release: "<<year<<endl;
}
string MP3::getsongname()const{
	return songname;
}
string MP3::getartname()const{
	return artname;
}
string MP3::getreview()const{
	return review;
}
int MP3::getyear()const{
	return year;
}
int MP3::getduration()const{
	return duration;
}
