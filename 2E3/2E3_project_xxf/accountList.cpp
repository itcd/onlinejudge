#include <string>
#include <iostream>
#include "account.h"
#include "accountList.h"
#include "customerList.h"
using namespace std;

accountList::accountList(){		//default constructor
        root=NULL;
        no=0;
		sumbalance=0.0;
}

accountList::~accountList(){		// destructor - modified, traversing through the tree
        if (root != NULL)
			delete root;
}

void accountList::add(account *data){	// add account, modified, adding to the tree
	account *p,*pp;			// insert into number ordered tree	
	int r;
	if (root== NULL){
		no=no+1;									//add number of account
		sumbalance=sumbalance;						//add total balance
		root=data;
        return;
    }

	p=root;
	pp=NULL;
	while(p){
		no++;										//add number of account
		sumbalance=sumbalance+(data->balance);		//add total balance
		pp=p;
		r=data->Compare(p);
			if (r>0){
				p=p->right;
			}
			else{
                p=p->left;
                }
    }
	if(r>0)
        {
                pp->right=data;
        }
        else
        {
                pp->left=data;
        }
}

account* accountList::findaccount (account *acc,int accid){
	if(acc==NULL){
		return NULL;
	}
	else if(acc->accountid==accid){
		acc->print();
		findcustomer(acc->customerid);
		return acc;
	}
	else if(accid>acc->accountid){
		return findaccount(acc->right,accid);
	}
	else return findaccount(acc->left,accid);
}
