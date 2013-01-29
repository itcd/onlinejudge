#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "Customer.h"
#include "Account.h"
#include "Tree.h"

using namespace std;

class Bank
{
public:
	Tree<Customer> customer_tree;
	Tree<Account> account_tree;
	vector<int> account_id_list;

	Bank()
	{
	}

	Bank(string filename)
	{
		read_file(filename);
	}

	void read_file(string filename)
	{
		// clear account id list first
		account_id_list.clear();

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

		int customer_count = 0;
		while (!in.eof()) {
			string line;
			getline(in, line);
			if (line.length() == 0)
				break;
			stringstream ss(line);
			Customer *c = new Customer();
			ss >> c->customerID >> c->lastName >> c ->firstName >> c->address;
			customer_tree.add(c);
			customer_count++;
		}

		cout<<"there are "<<customer_count<<" customers and ";

		int account_count = 0;
		int sum = 0;
		while (!in.eof()) {
			string line;
			getline(in, line);
			if (line.length() == 0)
				break;
			stringstream ss(line);
			Account *a = new Account();
			ss >> a->accountID >> a->customerID >> a->balance;
			account_tree.add(a);
			account_count++;
			sum += a->balance;
			account_id_list.push_back(a->accountID);
		}
		in.close();

		cout<<account_count<<" accounts."<<endl;
		cout<<"The sum of all accounts is "<<sum<<"."<<endl;
		if(customer_count > 0)
			cout<<"Average customer balance is "<<sum/(double)customer_count<<endl;
		else
			cout<<"There is no customer in the bank."<<endl;
	}

	int random_account_id()
	{
		return account_id_list[rand() % account_id_list.size()];
	}

	void transfer()
	{
		int id1, id2;
		do
		{
			id1 = random_account_id();
			id2 = random_account_id();
		}while(id1 == id2);

		Account * a1 = account_tree.find(id1);
		Account * a2 = account_tree.find(id2);
		a1->transfer(rand() % 1000, a2);
	}
};
