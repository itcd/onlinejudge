#pragma once
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

class account{
public:
	int accountid,customerid;
	double balance;
	account *left;
	account *right;

	account();
	~account();

	account(int accid, int cusid, int bal);
	void print();
	int Compare(account *data);
	void transfer(int,account*);//transfer money from this account to another
};