#include <string>
#include <iostream>
#include <fstream>
#include "student.h"
#include "studentList.h"

using namespace std;


studentList::studentList(){
	head =NULL;
	//tail =NULL;
	//n=0;
}

studentList::~studentList(){
	while (head!=NULL){
		student*p=head->next;
		delete head;
		head=p;
	}
}

void studentList::add(student*data){
	//if(tail==0){
	//	head=tail=data;
	//}
	//else{
	//		head!=NULL;
	//		student* current=head;
	//		while (current->next!=NULL &&current->compare(data)<=0){
	//			current=current->next;
	//		}
	//	}

	if(head == NULL || head->compare(data) > 0){
		data->next = head;
		head = data;
	}else{
		student *current = head;
		while(current->next != NULL && current->next->compare(data) <= 0){
			current = current->next;
		}
		data->next = current->next;
		if(current->next == head){
			head = current->next = data;
		}else{
			current->next = data;
		}
	}
}

void studentList::print(){
	ofstream out;
	out.open("student0.txt");
	if (out.fail()) {
		cout << "unable to open student0.txt" << endl;
		return;
	}
	//out << "COAKLEY Thomas 08000010 80" << endl;
	//out << "NORTON Helen 08000059 56";
	//out <<"student176.txt"<<endl;

	// write the linked list to file
	student*p=head;
	while (p){
		out<<p->surname<<"\t\t\t"<<p->firstname<<"\t\t\t"<<p->id<<"\t"<<p->mark;
		p=p->next;
		if(p) out<<endl;
	}

	out.close();
}
