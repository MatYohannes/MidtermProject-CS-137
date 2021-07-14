#include <iostream>
#include <iomanip>
using namespace std;
#include "Date.h"

int Date::checkDay(int testDay) const
{
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31,
		30, 31, 31, 30, 31, 30, 31};

	if (testDay > 0 && testDay <= daysPerMonth[month])
	{
		return testDay;
	}
	if(month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
	{
	  return testDay;
	}
	cout << "Invalid Day " << testDay << " was set to 1." << endl;
	return 1;
}

Date::Date(int m, int d, int y):month(m), day(d), year(y){}

Date::Date(const Date& right)
{
	month = right.getMonth();
	day = right.getDay();
	year = right.getYear();

	//cout << "The Date COPY constructor is complete." << endl;
}

Date::~Date()
{
	//cout << "The Date destrutor is complete." << endl;
}

Date& Date::setDate(int m, int d, int y)
{
	setMonth(m);

	if (checkDay(day) == 1)
	{
		checkDay(day);
	}
	else
	{
		setDay(d);
	}
	setYear(y);

	return *this;
}

Date& Date::setMonth(int m)
{
	month = m;
	return *this;
}

Date& Date::setDay(int d)
{
	day = d;
	return *this;
}

Date& Date::setYear(int y)
{
	year = y;
	return *this;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

ostream& operator << (ostream& output, const Date& right)
{
	output << setfill('0') << setw(2) << right.getMonth() << "/" << setfill('0') << setw(2) 
		<< right.getDay() << "/" << setfill('0') << setw(4) << right.getYear();

	return output;
}

istream& operator >> (istream& input, Date& right)
{
	input >> setw(2) >> setfill('0') >> right.month;
	input.ignore();
	input >> setw(2) >> setfill('0') >> right.day;
	input.ignore();
	input >> setw(4) >> setfill('0') >> right.year;

	//Checkday function can be added to cerr if wrong month day mix

	return input;
}

int Date::convertToDays() const
{
	int yearToDays = year * 365;
	int monthToDays = month * 30;

	return (yearToDays + monthToDays + day);
}

bool Date::operator > (const Date& right) const
{
	int yearToDays = year * 365;
	int monthToDays = month * 30;

	return (yearToDays + monthToDays + day) > right.convertToDays();
}

bool Date::operator < (const Date& right) const
{
	int yearToDays = year * 365;
	int monthToDays = month * 30;

	return (yearToDays + monthToDays + day) < right.convertToDays();
}

bool Date::operator >= (const Date& right) const
{
	int yearToDays = year * 365;
	int monthToDays = month * 30;

	return (yearToDays + monthToDays + day) >= right.convertToDays();
}

bool Date::operator <= (const Date& right) const
{
	int yearToDays = year * 365;
	int monthToDays = month * 30;

	return (yearToDays + monthToDays + day) <= right.convertToDays();
}

bool Date::operator == (const Date& right) const
{
	if (month == right.getMonth() && day == right.getDay() && year == right.getYear())
	{
		return true;
	}
	return false;
}

bool Date::operator != (const Date& right) const
{
	if (*this == right)
	{
		return false;
	}
	return true;
}


