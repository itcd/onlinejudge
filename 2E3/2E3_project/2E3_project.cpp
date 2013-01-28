#include <iostream>

#include "Bank.h"

using namespace std;

void main()
{
	cout<<"In bank0"<<endl;
	Bank bank0("bank0.txt");
	bank0.customer_tree.write("bank0.customer.txt");
	bank0.account_tree.write("bank0.account.txt");

	cout<<"In bank1"<<endl;
	Bank bank1("bank1.txt");
	bank1.customer_tree.write("bank1.customer.txt");
	bank1.account_tree.write("bank1.account.txt");
}
