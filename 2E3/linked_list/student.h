#pragma once
#include <string>
#include <iostream>

using namespace std;

class student{
public:
	string surname,firstname;
	int mark,id;

	student* next;

	student();
	student(string,string,int,int);

	int compare(student* data);
};