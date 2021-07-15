
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time2.h"

Time::Time(int h, int m) :hour(h), minute(m){}

Time::~Time()
{
	//cout << "The Time destructor is complete" << endl;
}

Time& Time::setTime(int h, int m)
{
	setHour(h);
	setMinute(m);

	return *this;
}

Time& Time::setHour(int h)
{
	hour = (h >= 0 || h < 24) ? h : 0;

	return *this;
}

Time& Time::setMinute(int m)
{
	minute = (m >= 0 || m < 60) ? m : 0;

	return *this;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

double Time::convertToDecimal() const
{

	double tempHour = hour;
	double tempMinute = minute / 60.0;

	return tempHour + tempMinute;
}

ostream& operator << (ostream& output, const Time& right)
{
	output << setfill('0') << setw(2) << right.getHour() << ":" << setfill('0') << setw(2) << right.getMinute();

	return output;
}

istream& operator >> (istream& input, Time& right)
{
	//	Enter time is this format: HH:MM AM (or PM)

	string meridiem = "AM";

	input >> setw(2) >> setfill('0') >> right.hour;
	input.ignore();
	input >> setw(2) >> setfill('0') >> right.minute;
	input.ignore();
	input >> setw(2) >> meridiem;

	if (!meridiem.compare("PM")) // Come back to this
	{
		right.setHour(right.getHour() + 12);
	}
	return input;
}

double Time::operator - (const Time& right)
{
	double newTime1 = this->convertToDecimal();
	double newTime2 = right.convertToDecimal();

	if (newTime1 < newTime2)
	{
		double finalTime = newTime2 - newTime1;
		return finalTime;
	}

	if (newTime1 > newTime2)
	{
		double finalState = 24;
		double difference = newTime1 - newTime2;
		finalState -= difference;
		return finalState;
	}
}

string Time::convertToStandard() const
{
	int tempHour = getHour();
	int tempMin = getMinute();

	string stringMin = to_string(tempMin);

	if (tempMin < 10)
	{
		stringMin = "0" + stringMin;
	}

	if (tempHour > 12)
	{
		string tempTime = to_string(tempHour - 12) + ":" + stringMin + " PM";
		return tempTime;
	}
	else if (tempHour == 12)
	{
		string tempTime = to_string(tempHour) + ":" + stringMin + " PM";
		return tempTime;
	}
	else
	{
		string tempTime = to_string(tempHour) + ":" + stringMin + " AM";
		return tempTime;
	}

}