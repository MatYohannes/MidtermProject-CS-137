/*
	Mathewos Yohannes
	CS 137
	Homework #3
	7/8/2021
*/



#ifndef DATE_H
#define DATE_H

/*
--------------------------------------------------------------------
						Date
--------------------------------------------------------------------
		- month : int
		- day : int
		- year : int
		- checkDay( : int) : const int
--------------------------------------------------------------------
		+ Date( : int, : int, : int)
		+ Date( : Date& const)
		+ ~Date()
		
		+ setDate( : int, : int, : int) : Date&
		+ setMonth( : int) : Date&
		+ setDay( : int) : Date&
		+ setYear( : int) : Date&

		+ getMonth() : const int
		+ getDay() : const int
		+ getYear() : const int

		+ convertToDays() : const int

		+ operator > ( : const Date&) : bool
		+ operator < ( : const Date&) : bool
		+ operator >= ( : const Date&) : bool
		+ operator <= ( : const Date&) : bool
		+ operator == ( : const Date&) : bool
		+ operator != ( : const Date&) : bool
--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
					<<C++Global>>
--------------------------------------------------------------------
		-  operator << ( : ostream&, : const Date&) : ostream&
		-  operator >> ( : istream&, : Date&) : istream&;
--------------------------------------------------------------------

--------------------------------------------------------------------
*/

class Date
{
	friend ostream& operator << (ostream& output, const Date& right);
	friend istream& operator >> (istream& input, Date& right);

private:
	int month;
	int day;
	int year;
	int checkDay(int) const;

public:
	Date(int m = 1, int d = 1, int y = 1990);
	Date(const Date& right);
	~Date();
	Date& setDate(int m, int d, int y);
	Date& setMonth(int m);
	Date& setDay(int d);
	Date& setYear(int y);

	int getMonth() const;
	int getDay() const;
	int getYear() const;

	int convertToDays() const; // calculate off by 0.04% and lower after year 1000


	bool operator > (const Date& right) const;
	bool operator < (const Date& right) const;
	bool operator >= (const Date& right) const;
	bool operator <= (const Date& right) const;
	bool operator == (const Date& right) const;
	bool operator != (const Date& right) const;
};

#endif // !DATE_H
