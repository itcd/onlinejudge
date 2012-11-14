#pragma once
#include <string>
#include <iostream>
using namespace std;

class MP3 {

private:
	string songname, artname,review;
	int duration, year;

public:
	MP3();
	void print ();
	string getsongname()const;
	string getartname()const;
	string getreview()const;
	int getduration()const;
	int getyear()const;

	MP3(string songname, string artname, string review, int duration, int year)
	{
		this->songname = songname;
		this->artname = artname;
		this->review = review;
		this->duration = duration;
		this->year = year;
	}
};