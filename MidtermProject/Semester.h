#ifndef SEMESTER_H
#define SEMESTER_H
#include "Date.h"

/*
--------------------------------------------------------------------
					Semester
--------------------------------------------------------------------
		- name : string
		- startOf : Date
		- endOf : Date
--------------------------------------------------------------------
		+ Semester( : string, : Date, : Date)

		+ setSemester( : string, : Date, : Date) : Semester&
		+ setName( : string) : Semester&
		+ setStartOf( : Date) : Semester&
		+ setEndOf( : Date) : Semester&

		+ getName() : const string
		+ getStartOf() : const Date
		+ getEndOf() : const Date

--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
							 <<C++Global>>
--------------------------------------------------------------------
		-  operator << ( : ostream&, : const Semester&) : ostream&
		-  operator >> ( : istream&, : Semester&) : istream&;
--------------------------------------------------------------------

--------------------------------------------------------------------
*/

class Semester
{
	friend ostream& operator << (ostream& output, const Semester& right);
	friend istream& operator >> (istream& input, Semester& right);

private:
	string name;
	Date startOf;
	Date endOf;

public:
	Semester(string n = "Fall 1990", Date begin = Date(), Date finish = Date());

	Semester& setSemester(string, Date, Date);
	Semester& setName(string);
	Semester& setStartOf(Date);
	Semester& setEndOf(Date);

	string getName() const;
	Date getStartOf() const;
	Date getEndOf() const;
};


#endif // !SEMESTER_H
