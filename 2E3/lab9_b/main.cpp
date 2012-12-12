#include <iostream>				// cout
#include <fstream>              // ifstream

#include "studentList.h"		// NB. also includes student.h
#include "StudentTree.h"

using namespace std;

#define FN	"student10000.txt"	// hardwired file name

StudentList studentList;		// global studentList
StudentTree tree;

//
// main
//
int main()
{

	//
	// read in data from student.txt
	//
	ifstream in;
	in.open(FN);
	if (in.fail()) {
		cout << "unable to open " << FN << endl;
		getchar();	// type key to dismiss window
		return 0;
	}

	//while (!in.eof()) {
	//	Student *student = new Student();
	//	in >> student->lastName >> student ->firstName >> student->id >> student->mark;
	//	studentList.add(student);
	//}
	while (!in.eof()) {
		Student *student = new Student();
		in >> student->lastName >> student ->firstName >> student->id >> student->mark;
		studentList.add(student);

		StudentNode *s = new StudentNode();
		s->lastName = student->lastName;
		s->firstName = student->firstName;
		s->id = student->id;
		s->mark = student->mark;
		tree.add(s);
	}
	in.close();

	//
	// generate result file

	studentList.write("studentOutput.txt");
	tree.write("studentOutputTree.txt");

	//StudentList *MyList = new StudentList();	

	string f, l;

	cout << "Type in the First Name: " ;
	cin >> f;
	cout << "Type in the Last Name: " ;
	cin >> l;

	cout<<"Linked list:"<<endl;

	// This line will cause errors, accessing invalid memory address.
	//Student *s = MyList->FindStudent(f, l, studentList);

	// This line is good, studentList is passed by pointer, no errors.
	//Student *s = MyList->FindStudent(f, l, &studentList);

	// This line is good, not passing studentList as parameter at all.
	Student *s = studentList.FindStudent(f, l);

	if ( s != NULL ) ///////////////////////////////////////////////////////////***
	{
		cout << "Student found: " << s->firstName << " " << s->lastName << " " << s->id<< " " << s->mark << endl;
		//cout << "Student found: " << s << endl; 
	}
	else
	{
		cout << "No such student found." << endl; 
	}

	cout<<"Binary search tree:"<<endl;

	StudentNode *sn = tree.FindStudent(f, l);

	if ( sn != NULL ) ///////////////////////////////////////////////////////////***
	{
		cout << "Student found: " << sn->firstName << " " << sn->lastName << " " << sn->id << " " << sn->mark << endl;
	}
	else
	{
		cout << "No such student found." << endl; 
	}

	//cout << "Number Of Comparisons made:" << MyList->numberOfComparisons << endl; 


	return 0;
}
