#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H
#include <iostream>
using namespace std;
#include <string>
#include "Time2.h"
#include "Date.h"
#include "Semester.h"
#include "Course.h"


/*
--------------------------------------------------------------------
						CourseSchedule
--------------------------------------------------------------------
		- studentName : string
		- studentSemester: Semester
		- studentCourse : Course*
		- maxSize : int
		- numCourses : int
		- checkDates( : Semester, : const Date&, : const Date&)
--------------------------------------------------------------------
		+ CourseSchedule( : string, : string, : int)
		+ CourseSchedule( : const CourseSchedule&)
		+ ~CourseSchedule()

		+ getStudentName() const
		+ getStudentSemester() const Semester
		+ getStudentCourse() const Course*
		+ getMaxSize () const int
		+ getNumCourse() const int

		+ setStudentName( : string) string
		+ addCourse( : const Course&) Course*
		+ removeCourse( : const Course&) Course*

--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
					<<C++Global>>
--------------------------------------------------------------------
		-  operator << ( : ostream&, : const CourseSchedule&) : ostream&
--------------------------------------------------------------------
*/



class CourseSchedule
{
	friend ostream& operator << (ostream& output, const CourseSchedule& right);

private:
	string studentName;
	Semester studentSemester;
	Course* studentCourse;
	int maxSize;
	int numCourses;
	bool checkDates(const Semester semes, const Date& startDate, const Date& endDate) const;

public:
	CourseSchedule(string name = "Jane Doe", Semester semes = Semester(), int mSize = 4);

	~CourseSchedule();

	string getStudentName() const;
	Semester getStudentSemester() const;
	Course* getStudentCourse() const;
	int getMaxSize() const;
	int getNumCourses() const;

	string setStudentName(string name);

	Course* addCourse(const Course& right);
	Course* removeCourse(string cName);

	
};


#endif // !COURSESCHEDULE_H

