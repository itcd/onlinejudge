#pragma once

#include <string>

using namespace std;

class Student {

public:

	string firstName;			// first name
	string lastName;			// last name
	int id;						// student ID
	int mark;					// student mark

	Student *next;				// link to next student

	Student();					// default constructor
	int cmp(Student*);		    // compare students 

};
