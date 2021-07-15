
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time2.h"
#include "Course.h"
#include "Date.h"

Course::Course(string cName, string cNumber, string mDays, double value,
	Date sDate, Date eDate, Time sTime, Time eTime)
	:courseName(cName), courseNumber(cNumber), meetingDays(mDays),
	units(value), startDate(sDate), endDate(eDate), startTime(sTime), endTime(eTime) {}


Course::~Course()
{
	//cout << "The Course destructor is completed" << endl;
}

string Course::getCourseName() const
{
	return courseName;
}

string Course::getCourseNumber() const
{
	return courseNumber;
}

string Course::getMeetingDays() const
{
	return meetingDays;
}

double Course::getUnits() const
{
	return units;
}

Date Course::getStartDate() const
{
	return startDate;
}

Date Course::getEndDate() const
{
	return endDate;
}

Time Course::getStartTime() const
{
	return startTime;
}

Time Course::getEndTime() const
{
	return endTime;
}

Course& Course::setCourseName(string cName)
{
	courseName = cName;
	return *this;
}

Course& Course::setCourseNumber(string cNumber)
{
	courseNumber = cNumber;
	return *this;
}

Course& Course::setMeetingDays(string mDays)
{
	meetingDays = mDays;
	return *this;
}

Course& Course::setUnits(double value)
{
	units = value;
	return *this;
}

Date& Course::setStartDate(Date sDate)
{
	startDate = sDate;
	return startDate;

}

Date& Course::setEndDate(Date eDate)
{
	endDate = eDate;
	return endDate;

}

Time& Course::setStartTime(Time sTime)
{
	startTime = sTime;
	return startTime;
}

Time& Course::setEndTime(Time eTime)
{
	endTime = eTime;
	return endTime;
}

double Course::calcDailyDuration() const
{

	Time start = getStartTime();
	Time end = getEndTime();

	if (isnan(start - end))
	{
		return 0.0;
	}
	return (start -end);
}

ostream& operator << (ostream& output, const Course& right)
{
	output << "Course Info:     " << right.getCourseNumber() << " -- " << right.getCourseName() << endl;
	output << "# of Units:      " <<  setprecision(1) << fixed << right.getUnits() << endl;
	output << setprecision(0)  << resetiosflags(ios::fixed) << "Course Dates:    " << right.getStartDate() << " - " << right.getEndDate() << endl;
	output << "Meeting Days:    " << right.getMeetingDays() << endl;
	output << "Meeting Time:    " << right.getStartTime().convertToStandard() << " - " << right.getEndTime().convertToStandard() << endl;
	output << "Daily Duration:  "  << setprecision(2) << fixed << right.calcDailyDuration() << " hours\n" << endl;
	
	return output;
}





