#include <iomanip>			// setw(), setfill()

#include "student.h"		//

//
// default constructor
//
Student::Student()
{
	firstName = lastName = "";
	id = 0;
	mark = 0;
	next = NULL;
}


int Student::cmp(Student *rhs)
{
	if (int r = lastName.compare(rhs->lastName))
		return r;
	return firstName.compare(rhs->firstName);
}
