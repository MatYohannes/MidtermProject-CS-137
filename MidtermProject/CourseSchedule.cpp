#include <iostream>
using namespace std;
#include <string>
#include "Time2.h"
#include "Date.h"
#include "Semester.h"
#include "Course.h"
#include "CourseSchedule.h"


bool CourseSchedule::checkDates(const Semester semes,const Date& startDate,const Date& endDate) const
{
	Date semStart = semes.getStartOf();
	Date semEnd = semes.getEndOf();

	if (startDate.convertToDays() < semStart.convertToDays())
	{
		return false;
	}
	if ( endDate.convertToDays()  > semEnd.convertToDays())
	{
		return false;
	}

	return true;
}

CourseSchedule::CourseSchedule(string name, Semester semes, int mSize)
	:studentName(name), studentSemester(semes), maxSize(mSize)
{
	numCourses = 0;
	studentCourse = new Course[maxSize];

	for (int i = 0; i < maxSize; i++)
	{
		studentCourse[i] = Course("Null", "Null", "Null", 0.0, Date(), Date(), Time(), Time());
	}
}

CourseSchedule::~CourseSchedule()
{
	//delete studentCourse, explain the breakpoint issue that occured with team
	cout << "The CourseSchedule Destructor is complete" << endl;
}

string CourseSchedule::getStudentName() const
{
	return studentName;
}

Semester CourseSchedule::getStudentSemester() const
{
	return studentSemester;
}

Course* CourseSchedule::getStudentCourse() const
{
	return studentCourse;
}

int CourseSchedule::getMaxSize() const
{
	return maxSize;
}

int CourseSchedule::getNumCourses() const
{
	return numCourses;
}

string CourseSchedule::setStudentName(string name)
{
	studentName = name;
	return studentName;
}


Course* CourseSchedule::addCourse(const Course& right)
{
	if (checkDates(studentSemester, right.getStartDate(), right.getEndDate()))
	{
		studentCourse[numCourses] = right;
		numCourses += 1;
		return studentCourse;
	}
	else
	{
		cout << "\nThe course dates do not match up with the semester. Can not add this course." << endl;
		return studentCourse;
	}
}

Course* CourseSchedule::removeCourse(string cName)
{
	for (int i = 0; i < getMaxSize(); i++)
	{
		if ((getStudentCourse()[i].getCourseNumber()).compare(cName) == 0)
		{
			if (i != getMaxSize() - 1)
			{
				studentCourse[i] = studentCourse[i + 1];

				for (int j = i + 1; j < getMaxSize(); j++)
				{
					studentCourse[j - 1] = studentCourse[j];
				}
				numCourses -= 1;
				studentCourse[getMaxSize() - 1] = Course("Null", "Null", "Null", 0.0, Date(), Date(), Time(), Time());
				return studentCourse;
			}
			else
			{
				studentCourse[i] = Course("Null", "Null", "Null", 0.0, Date(), Date(), Time(), Time());
				return studentCourse;
			}
		}
	}
	cout << "\nNo class matches that name in the course schedule. Please try a different class name." << endl;
	return studentCourse;
}

ostream& operator << (ostream& output, const CourseSchedule& right)
{
	output << "CLASS SCHEDULE" << endl;
	output << "-----------------------" << endl;
	output << "Name: " << right.getStudentName() << endl;
	output << "Semester: " << right.getStudentSemester() << endl;
	output << "Number of Classes: " << right.getNumCourses() << endl;
	output << "-----------------------------------------" << endl;
	
	for (int i = 0; i < right.maxSize; i++)
	{
		cout << right.getStudentCourse()[i];
	}
	return output;
}
