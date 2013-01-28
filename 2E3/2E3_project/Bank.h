#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "Customer.h"
#include "Account.h"
#include "Tree.h"

using namespace std;

class Bank
{
public:
	Tree<Customer> customer_tree;
	Tree<Account> account_tree;

	Bank(string filename)
	{
		//
		// read in data from student.txt
		//
		ifstream in;
		in.open(filename);
		if (in.fail()) {
			cout << "unable to open " << filename << endl;
			getchar();	// type key to dismiss window
			return;
		}

		int count = 0;
		while (!in.eof()) {
			string line;
			getline(in, line);
			//cout<<"line length "<<line.length()<<endl<<line<<endl;
			if (line.length() == 0)
			{
				break;
			}
			stringstream ss(line);
			Customer *tmp = new Customer();
			ss >> tmp->customerID >> tmp->lastName >> tmp ->firstName >> tmp->address;
			customer_tree.add(tmp);
			count++;
		}

		cout<<"There are "<<count<<" customers."<<endl;

		count = 0;
		while (!in.eof()) {
			Account *tmp = new Account();
			in >> tmp->accountID >> tmp->customerID >> tmp->balance;
			account_tree.add(tmp);
			count++;
		}
		in.close();

		cout<<"There are "<<count<<" accounts."<<endl;
	}
};
