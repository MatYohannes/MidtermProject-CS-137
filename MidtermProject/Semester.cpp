#include <iostream>
using namespace std;
#include "Semester.h"
#include "Date.h"



Semester::Semester(string n, Date begin, Date finish)
	:name(n), startOf(begin), endOf(finish) {}

Semester& Semester::setSemester(string n, Date begin, Date finish)
{
	setName(n);
	setStartOf(begin);
	setEndOf(finish);

	return *this;
}

Semester& Semester::setName(string n)
{
	name = n;
	return *this;
}

Semester& Semester::setStartOf(Date begin)
{
	startOf = begin;
	return *this;
}

Semester& Semester::setEndOf(Date finish)
{
	endOf = finish;
	return *this;
}

string Semester::getName() const
{
	return name;
}

Date Semester::getStartOf() const
{
	return startOf;
}

Date Semester::getEndOf() const
{
	return endOf;
}

ostream& operator << (ostream& output, const Semester& right)
{
	output << "Semester: " << right.getName() << " ("
		<< right.getStartOf() << " - " << right.getEndOf() << ")" << endl;

	return output;
}

istream& operator >> (istream& input, Semester& right)
{
	string sems;
	string year;
	input >> sems >> year;
	input.ignore(2);
	input >> right.startOf;
	input.ignore(3);
	input >> right.endOf;
	input.ignore();

	right.name = sems + " " + year;
	
	return input;
}

