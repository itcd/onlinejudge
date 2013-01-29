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
		ss << "Customer\t" << customerID << "\t" << lastName << "\t" << firstName << "\t" << address <<endl;
		return ss.str();
	}

	void set_ID(int ID)
	{
		customerID = ID;
	}

	int get_value()
	{
		return 0; // no balance for customer
	}

	static bool has_balance()
	{
		return false;
	}
};
