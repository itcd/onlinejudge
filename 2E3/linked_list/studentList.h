#pragma once
#include <string>
#include <iostream>
#include "student.h"

using namespace std;

class studentList{
public:
	student* head;
	//student* tail;
	//int n;

	studentList();
	~studentList();

	void add(student* data);
	void print();
	//bool remove(student* data);
};