#pragma once
#include <string>
#include <iostream>
#include "account.h"
#include "customerList.h"
using namespace std;

class accountList{
public:
	int no;
	double sumbalance;
	//customerList *cusl;
	account *root;

	accountList();
	~accountList();

	void add(account *data);
	account *findaccount (account *acc,int accid); 
};