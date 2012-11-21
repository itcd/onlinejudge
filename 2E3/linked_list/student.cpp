#include <iostream>
#include <string>
#include "student.h"

student::student(){
	surname="";
	firstname="";
	mark=0;
	id=0;
	next=NULL;
}

student::student(string sname,string fname,int no,int Mark){
	surname=sname;
	firstname=fname;
	id=no;
	mark=Mark;
	next=NULL;
}

int student::compare(student* data){
	if (surname.compare(data->surname)==0){
		if(firstname.compare(data->firstname)>0){
			return 1;
		}
		else if (firstname.compare(data->firstname)<0){
			return -1;
		}
		else return 0;
	}
	else if (surname.compare(data->surname)>0){
		return 1;
	}
	else return -1;
}



