
#ifndef TIME_H
#define TIME_H

/*
--------------------------------------------------------------------
						Time
--------------------------------------------------------------------
		- hour : int
		- minute : int
--------------------------------------------------------------------
		
		+ Time( : int, : int)
		+ ~Time()

		+ setTime( : int, : int) Time&
		+ setHour( : int) : Time&
		+ setMinute( : int) : Time&
		+ getHour() : int const
		+ getMinute() : int const
		+ convertToDecimal() : double const
		+ operator - ( : Time& const) : double
		+ convertToStandard() : string const
		
--------------------------------------------------------------------
*/

/*
--------------------------------------------------------------------
					<<C++Global>>
--------------------------------------------------------------------
		-  operator << ( : ostream&, : const Course&) : ostream&
		-  operator >> ( : istream&, : Time&) : istream&
--------------------------------------------------------------------

--------------------------------------------------------------------
*/

class Time
{
	friend ostream& operator << (ostream& output, const Time& right);
	friend istream& operator >> (istream& input, Time& right);

private:
	int hour;
	int minute;
	
public:
	Time(int h = 0, int m = 0);
	~Time();

	Time& setTime(int, int);
	Time& setHour(int);
	Time& setMinute(int);
	int getHour() const;
	int getMinute() const;
	double convertToDecimal() const;
	double operator - (const Time& right);

	string convertToStandard() const;
};

#endif // !TIME_H
