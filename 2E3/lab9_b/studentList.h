#pragma once

#include "student.h"

class StudentList 
{

public:

	int numberOfComparisons;	

	StudentList();				// default constructor
	~StudentList();				// destructor
	void add(Student*);			// add student to list
	void write(string);		     	// write to file

	Student* StudentList::FindStudent (string f, string l, StudentList SL);
	Student* StudentList::FindStudent (string f, string l, const StudentList *SL);
	Student* StudentList::FindStudent (string f, string l);

private:

	Student *head;				// head of list
	int n;					// number of Student in list
	int mode;				// sort mode

};

// eof
