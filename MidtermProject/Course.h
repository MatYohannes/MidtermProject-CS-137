#ifndef COURSE_H
#define COURSE_H
using std::string;

#include "Time2.h"
#include "Date.h"


/*
--------------------------------------------------------------------
						Course
--------------------------------------------------------------------
		- courseName : string
		- courseNumber : string
		- meetingDays : string
		- units : double
		- startDate : Date
		- endDate : Date
		- startTime : Time
		- endTime : Time
--------------------------------------------------------------------
		+ Course( : string, : string, : string, : double,
		        : Date, : Date, : Time, : Time)
		+ ~Course()

		+ getCourseName() : const string
		+ getCourseNumber() : const string
		+ getMeetingDays() : const string
		+ getUnits() : const double
		+ getStartDate() : const Date
		+ getEndDate() : const Date
		+ getStartTime() : const Time
		+ getEndTime() : const Time
		+ setCourseName( : string) : Course&
		+ setCourseNumber( : string) : Course&
		+ setMeetingDays( : string) : Course&
		+ setUnits( : double) : Course&
		+ setStartDate( : Date) : Date&
		+ setEndDate( : Date) : Date&
		+ setStartTime( : Time) : Time&
		+ setEndTime( : Time) : Time&
		+ calcDailyDuration() : double
--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
					<<C++Global>>
--------------------------------------------------------------------
		-  operator << ( : ostream&, : const Course&) : ostream&
--------------------------------------------------------------------

--------------------------------------------------------------------
*/

class Course
{
	friend ostream& operator << (ostream& output, const Course& right);

private:
	string courseName;
	string courseNumber;
	string meetingDays;
	double units;
	Date startDate;
	Date endDate;
	Time startTime;
	Time endTime;

public:
	Course(string courseName = "Name", string courseNumber = "Number",string meetingDays = "Day",
		double units = 0.0, Date startDate = Date(),
		Date endDate = Date(), Time startTime = Time(), Time endTime = Time());
	
	~Course();
	string getCourseName() const;
	string getCourseNumber() const;
	string getMeetingDays() const;
	double getUnits() const;
	
	Date getStartDate() const;
	Date getEndDate() const;
	Time getStartTime() const;
	Time getEndTime() const;

	Course& setCourseName(string cName);
	Course& setCourseNumber(string cNumber);
	Course& setMeetingDays(string mDays);
	Course& setUnits(double right);

	Date& setStartDate(Date sDate);
	Date& setEndDate(Date eDate);
	Time& setStartTime(Time sTime);
	Time& setEndTime(Time eTime);

	double calcDailyDuration() const;
};

#endif // !COURSE_H















