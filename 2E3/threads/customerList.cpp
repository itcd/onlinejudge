#include <string>
#include <iostream>
#include "customer.h"
#include "customerList.h"
using namespace std;

customerList::customerList(){		//default constructor
        root=NULL;
        number=0;
}

customerList::~customerList(){		// destructor - modified, traversing through the tree
        if (root != NULL)
			delete root;

}

void customerList::add(customer *data){	// add customer, modified, adding to the tree
	customer *p,*pp;			// insert into number ordered tree	
	int r;
	if (root== NULL){
		number=number+1;
		root=data;
        return;
    }

	p=root;
	pp=NULL;
	while(p){
		number++;
		pp=p;
		r=data->comPare(p);
			if (r>0){
				p=p->right;
			}
			else{
                p=p->left;
                }
    }