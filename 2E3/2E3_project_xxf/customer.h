#pragma once
#include <string>
#include <iostream>
using namespace std;

class customer{
public:
	int id;
	string firstname,surname;
	string town;
	customer *left;
	customer *right;
	
	customer();
	customer(int,string,string,string);
	~customer();
	void print();
	int comPare(customer *data);
};
