#pragma once
#include <string>
#include <iostream>
#include "customer.h"
using namespace std;

class customerList{
public:
	int number;
	customer *root;

	customerList();
	~customerList();

	void add(customer *data);
	customer *findcustomer (customer *cus,int customerid); //display insert customer
	//void print();
};