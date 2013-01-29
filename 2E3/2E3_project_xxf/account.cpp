#include <string>
#include <iostream>
#include "account.h"

account::account(){
	accountid=0;
	customerid=0;
	balance=0.0;
	left=right=NULL;
}

account::~account(){
	if (left != NULL) 
		delete left;
	if (right != NULL) 
		delete right; 
}

account::account(int accid, int cusid, int bal){
	accid=accountid;
	cusid=customerid;
	bal=balance;
	left=right=NULL;
}

void account::print(){
	cout<<"cusutomer id:"<<customerid<<endl;
	cout<<"account id:"<<accountid<<endl;
    cout<<"balance:"<<balance<<endl;
}

int account::Compare(account *data){
	if (customerid==data->customerid){
		return 0;
	}
	else if (customerid>data->customerid){
		return 1;
	}
	else return -1;
}

void account::transfer(int v, account *toAccount){
	balance -= v; // debit this account
	toAccount->balance += v; // credit toAccount
}