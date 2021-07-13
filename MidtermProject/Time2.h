
#ifndef TIME_H
#define TIME_H

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
};

#endif // !TIME_H
