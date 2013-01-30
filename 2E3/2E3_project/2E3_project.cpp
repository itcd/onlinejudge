#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread> // C++11 (C++0x) thread library. Visual Studio 2010 or above is required.

#include "Bank.h"

using namespace std;

const int THREADS_FOR_EACH_BANK = 8;

void main()
{
	/* initialize random seed: */
	srand ( time(NULL) );

	const int N = 2;
	Bank banks[N];
	banks[0].set_ID(0);
	banks[1].set_ID(1);
	banks[0].read_file("bank0.txt");
	banks[1].read_file("bank1.txt");

	//// write data to files
	//banks[0].customer_tree.write("bank0.customer.txt");
	//banks[0].account_tree.write("bank0.account.txt");
	//banks[1].customer_tree.write("bank1.customer.txt");
	//banks[1].account_tree.write("bank1.account.txt");

	////////////////////////////////////////////////////////////////
	// display information
	////////////////////////////////////////////////////////////////

	int bank_id, customer_id, account_id;

	do
	{
		cout<<"Enter a bank id and a customer id"<<endl;
		cin>>bank_id>>customer_id;
	}while(bank_id <0 || bank_id >= N || customer_id < 80000000);

	Customer * c = banks[bank_id].customer_tree.find(customer_id);
	if(c)
		cout<<c->to_string()<<endl;
	else
		cout<<"Customer not found."<<endl;

	do
	{
		cout<<"Enter a bank id and an account id"<<endl;
		cin>>bank_id>>account_id;
	}while(bank_id <0 || bank_id >= N || account_id < 90000000);

	Account * a = banks[bank_id].account_tree.find(account_id);
	if(a)
	{
		cout<<a->to_string()<<endl;
		Customer * c0 = banks[bank_id].customer_tree.find(a->customerID);
		if(c0)
			cout<<c0->to_string()<<endl;
		else
			cout<<"Customer not found."<<endl;
	}else
	{
		cout<<"Account not found."<<endl;
	}
	
	////////////////////////////////////////////////////////////////
	// transfer money
	////////////////////////////////////////////////////////////////

	cout<<endl<<"Transfer money among accounts."<<endl;
	cout<<endl<<"Starting threads..."<<endl;

	std::vector<std::thread> threads;
	for (int i=0; i<THREADS_FOR_EACH_BANK; i++)
	{
		threads.push_back(std::thread(&Bank::transfer, &banks[0]));
		threads.push_back(std::thread(&Bank::transfer, &banks[1]));
	}
	for (int i=0; i<threads.size(); i++)
	{
		threads[i].join();
	}

	cout<<endl<<"All threads finished."<<endl;

	cout<<"Bank balance"<<endl;
	cout<<banks[0].account_tree.sum()<<endl;
	cout<<banks[1].account_tree.sum()<<endl;
}
