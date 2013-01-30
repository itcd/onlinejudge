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

	void transfer(int v, Account *toAccount)
	{
		balance -= v; // debit this account
		toAccount->balance += v; // credit toAccount
	}

	// compare
	int cmp(Account *rhs)
	{
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
		ss << "(Account " << accountID << " " << customerID << " " << balance << ")" <<endl;
		return ss.str();
	}

	void set_ID(int ID)
	{
		accountID = ID;
	}

	int get_value()
	{
		return balance;
	}

	static bool has_balance()
	{
		return true;
	}
};
