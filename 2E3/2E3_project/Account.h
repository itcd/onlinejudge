#pragma once

#include <string>
#include <sstream>
using namespace std;

class Account
{
public:
	Account *left;				// link to left
	Account *right;				// link to right

	int accountID;
	int customerID;
	int balance;

	Account()
	{
		balance = accountID = customerID = 0;
		left = right = NULL;
	}

	// compare
	int cmp(Account *rhs)
	{
		//if (int r = lastName.compare(rhs->lastName))
		//	return r;
		//return firstName.compare(rhs->firstName);

		if (accountID < rhs->accountID)
			return -1;
		else
			if (accountID > rhs->accountID)
				return 1;
			else
				return 0;
	}

	string to_string()
	{
		stringstream ss;
		ss << accountID << "\t" << customerID << "\t" << balance <<endl;
		return ss.str();
	}
};
