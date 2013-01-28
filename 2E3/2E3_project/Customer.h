#pragma once

#include <string>
#include <sstream>

using namespace std;

class Customer
{
public:
	Customer *left;				// link to left
	Customer *right;				// link to right

	int customerID;
	string lastName;
	string firstName;
	string address;

	Customer()
	{
		address = firstName = lastName = "";
		customerID = 0;
		left = right = NULL;
	}

	// compare
	int cmp(Customer *rhs)
	{
		//if (int r = lastName.compare(rhs->lastName))
		//	return r;
		//return firstName.compare(rhs->firstName);

		if (customerID < rhs->customerID)
			return -1;
		else
			if (customerID > rhs->customerID)
				return 1;
			else
				return 0;
	}

	string to_string()
	{
		stringstream ss;
		ss << customerID << "\t" << lastName << "\t" << firstName << "\t" << address <<endl;
		return ss.str();
	}
};
