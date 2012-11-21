#include <string>
#include <iostream>
#include <fstream>
#include "student.h"
#include "studentList.h"

using namespace std;

int main(){

	studentList sl;
	ifstream in;
	in.open("student176.txt");
	if (in.fail()) {
		cout << "unable to open student.txt" << endl;
		return 0;
	}
	while (!in.eof()) {
		student *Student = new student();
		in >> Student->surname >> Student->firstname;
		in >> Student->id >> Student->mark;
	
		sl.add(Student);

	}
	in.close();

	sl.print();

	return 0;
}