#pragma once

#include <string>
using namespace std;

class StudentNode
{
public:
	string firstName;			// first name
	string lastName;			// last name
	int id;						// student ID
	int mark;					// student mark

	StudentNode *left;				// link to next student
	StudentNode *right;				// link to next student

	// compare students
	int cmp(StudentNode *rhs)
	{
		if (int r = lastName.compare(rhs->lastName))
			return r;
		return firstName.compare(rhs->firstName);
	}

	StudentNode()
	{
		firstName = lastName = "";
		id = mark = 0;
		left = right = NULL;
	}
};
