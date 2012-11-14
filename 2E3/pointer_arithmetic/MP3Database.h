#pragma once
#include "MP3.h"
#include <string>
#include <iostream>

using namespace std;

class MP3Database:public MP3{
public:
	MP3*list;
	int size;

	MP3Database (int size);
	~MP3Database();
	void print();
	void search(string artname);
};
