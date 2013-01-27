#include <string>
#include <iostream>
#include "customer.h"

customer::customer(){			// default constructor
	surname="";
	firstname="";
	town="";
	id=0;
	left = right = NULL;
}

customer::customer(int customerid,string sname,string fname,string city){
	id=customerid;
	surname=sname;
	firstname=fname;
	town=city;
	left = right = NULL;
}

customer::~customer(){
	if (left != NULL) 
		delete left;
	if (right != NULL) 
		delete right; 
}

void customer::print(){
        cout<<"cusutomer id:"<<id<<endl;
		cout<<"surname:"<<surname<<endl;
        cout<<"fistname:"<<firstname<<endl;
		cout<<"town:"<<town<<endl;
}

int customer::comPare(customer *data){
	if (id==data->id){
		return 0;
	}
	else if (id>data->id){
		return 1;
	}
	else return -1;
}