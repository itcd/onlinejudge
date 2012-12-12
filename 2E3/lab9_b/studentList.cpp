//#include "student.h"
#include <fstream>				// outstream
#include <iostream>				
#include <iomanip>			    // setw(), setfill()

#include "studentList.h"
//
// default constructor
//
StudentList::StudentList()
{
	head = NULL;
	n = mode = 0;
}

//
// destructor
//
StudentList::~StudentList()
{
	while (head) {
		Student *p = head->next;
		delete head;
		head = p;
	}
	cout<<"Linked list destroyed."<<endl;
}

//
// add student
//
void StudentList::add(Student *student)
{
	//
	// check if need to insert at head of list
	//
	if ((head == NULL) || (student->cmp(head) <= 0)) {
		student->next = head;
		head = student;
		return;
	}

	//
	// find insertion position
	//
	Student *p = head;	//Student *current = head;	
	while ((p->next) && (student->cmp(p->next) > 0))
		p = p->next;

	//
	// insert node into list at correct postion
	//
	student->next = p->next; //student->next = current->next;
	p->next = student;	//current->next = student;
}

void StudentList::write(string fn){


	ofstream out;
	out.open(fn.c_str());
	if (out.fail()) {
		cout << "unable to open " << fn << endl;
		return;
	}

	//go thru the list
	Student *p = head;
	while (p) {

		out << left << setw(16) << p->lastName; 
		out << setw(16) << p->firstName;
		out << setfill('0') << right << setw(8) << p->id << setfill(' ');
		out << setw(4) << p->mark;

		p = p->next;
		if (p)
			out << endl;
	}

	out.close();

}

/************************************************************************/
/*
The problem in this FindStudent method is that the parameter StudentList SL is pass-by-value, 
which means an copy of StudentList SL is created in the scope of this method.
When the method finishes, all local variables and parameters will be destroyed, 
including the copy of StudentList SL. So the destructor of StudentList will be called to clean up everything in the object.

Here comes the problem:
StudentList's destructor is called to destroy StudentList SL, i.e. the linked list that stores all the students.
The pointer p is valid when it is returned, but after the destructor is called, the linked list doesn't exist any more.
So when we try to print the content of pointer p in the main function, we access invalid memory address and it causes the error.

Two alternative approaches are written below.
*/
/************************************************************************/ 
Student* StudentList::FindStudent (string f, string l, StudentList SL)
{
	numberOfComparisons = 0;

	Student *p = SL.head;       
	while (p!=NULL) 
	{ 
		numberOfComparisons++;
		if (p->firstName.compare(f)==0 && p->lastName.compare(l)==0)      
		{
			cout << "Number Of Comparisons made:" << numberOfComparisons << endl;
			return p; 
		}

		p = p->next;        // go to next node 
	}
	cout<<"Not found!"<<endl;
	cout << "Number Of Comparisons made:" << numberOfComparisons << endl;

	return NULL;  
}
//return a pointer to Student with matching lastname and firstname
//or NULL if such student is not found.  

/************************************************************************/
/*
Solution 1: pass-by-reference (by pointer)
No copy of object is created, so it will not trigger the destructor.
*/
/************************************************************************/ 
Student* StudentList::FindStudent (string f, string l, const StudentList *SL)
{
	numberOfComparisons = 0;

	Student *p = SL->head;       
	while (p!=NULL) 
	{ 
		numberOfComparisons++;
		if (p->firstName.compare(f)==0 && p->lastName.compare(l)==0)      
		{
			cout << "Number Of Comparisons made:" << numberOfComparisons << endl;
			return p; 
		}

		p = p->next;        // go to next node 
	}
	cout<<"Not found"<<endl;
	cout << "Number Of Comparisons made:" << numberOfComparisons << endl;

	return NULL;  
}

/************************************************************************/
/*
Solution 2: Actually we don't need an extra StudentList *SL as parameter, 
if we use the StudentList object which its head is pointing to the head of the linked list.
*/
/************************************************************************/ 
Student* StudentList::FindStudent (string f, string l)
{
	numberOfComparisons = 0;

	Student *p = head;       
	while (p!=NULL) 
	{ 
		numberOfComparisons++;
		if (p->firstName.compare(f)==0 && p->lastName.compare(l)==0)      
		{
			cout << "Number Of Comparisons made:" << numberOfComparisons << endl;
			return p; 
		}

		p = p->next;        // go to next node 
	}
	cout<<"Not found"<<endl;
	cout << "Number Of Comparisons made:" << numberOfComparisons << endl;

	return NULL;  
}
