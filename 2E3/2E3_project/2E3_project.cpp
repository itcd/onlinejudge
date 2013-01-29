#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bank.h"

using namespace std;

//#include "windows.h" // CreateThread etc.
//#define MAXTHREADS 16 // max number of threads
//HANDLE threadH[MAXTHREADS]; // thread handles

void main()
{
	/* initialize random seed: */
	srand ( time(NULL) );

	const int N = 2;
	Bank banks[N];
	cout<<"In bank0, ";
	banks[0].read_file("bank0.txt");
	cout<<"\nIn bank1, ";
	banks[1].read_file("bank1.txt");

	//banks[0].customer_tree.write("bank0.customer.txt");
	//banks[0].account_tree.write("bank0.account.txt");

	//banks[1].customer_tree.write("bank1.customer.txt");
	//banks[1].account_tree.write("bank1.account.txt");

	////////////////////////////////////////////////////////////////
	// display information
	////////////////////////////////////////////////////////////////
	cout<<endl;

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

	cout<<endl<<"Transfer money between accounts."<<endl;
	banks[0].transfer();
	banks[0].transfer();
	banks[1].transfer();
	banks[1].transfer();

	cout<<"Bank balance"<<endl;
	cout<<banks[0].account_tree.sum()<<endl;
	cout<<banks[1].account_tree.sum()<<endl;
}
