#include <iostream>
using namespace std;
#include "Time2.h"
#include "Date.h"
#include "Semester.h"
#include "Course.h"
#include "CourseSchedule.h"
using std::string;


int main()
{
	cout << "Welcome to the Imaginary College" << endl;

	// Asking for name, semester name, semester start day, semester end day, number of classes taking
	string personName;
	cout << "Please enter your name: ";
	getline(cin, personName);
	string personSemester;
	cout << "Please enter the semester you are joining in this format: Fall 2019 \n";
	getline(cin, personSemester);
	Date personStartDate;
	cout << "Please enter the start date of semester is this format: 7/4/2021 \n";
	cin >> personStartDate;
	Date personEndDate;
	cout << "Please enter the end date of semester is this format: 7/4/2021 \n";
	cin >> personEndDate;
	int numOfClasses;
	cout << "How many classes do you plan to take?" << endl;
	cin >> numOfClasses;

	// Creating Semester and Course Schedule objects
	Semester currentSemester(personSemester, personStartDate, personEndDate);
	CourseSchedule personCourseSchedule(personName, currentSemester, numOfClasses);

	// Menu
	char choice;
	do {

		cout << "COURSE ENTRY MENU FOR:	  " << currentSemester.getName() << " (" << currentSemester.getStartOf() << ' - ' << currentSemester.getEndOf() << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1) Enter a new course\n";
		cout << "2) Remove a course\n";
		cout << "3) Print a Semester Schedule\n";
		cout << "q) Quit the program" << endl;

		cin >> choice;

		if (choice == '1')
		{
			string classNumber;
			string className;
			string classDays;
			int unitsValue;

			// Asking for class number, class name, class meeting days and class unit
			cout << "\nEntering a new course selected\n";
			cout << "----------------------------------\n";
			cout << "Please provide a course number: ";
			getline(cin, classNumber);
			cout << "Please provide a course name: ";
			getline(cin, className);
			cout << "Please provide the meeting days for the course: ";
			getline(cin, classDays);
			cout << "Please provide the number of units the course is worth: ";
			cin >> unitsValue;

			// Asking for start and end time
			Time classStartTime;
			cout << "Please enter the starting time for the course in this format:   7:30 PM\n";
			cin >> classStartTime;
			Time classEndTime;
			cout << "Please enter the ending time for the course i this format:   7:30 PM\n";
			cin >> classEndTime;

			// Asking for start and end date
			Date classStartDate;
			cout << "Please enter the start date for the course in this format: 7/4/2021 \n";
			cin >> classStartDate;
			Date classEndDate;
			cout << "Please enter the end date for the course in this format: 7/4/2021 \n";
			cin >> classEndDate;

			Course course1(className, classNumber, classDays, unitsValue, classStartDate, classEndDate, classStartTime, classEndTime);

			// Adding course1 to user course schedule
			personCourseSchedule.addCourse(course1);
		}
		
		if (choice == '2')
		{

		}

		if (choice == '3')
		{
			cout << personCourseSchedule;
		}

	} while (choice != 'q' && choice != 'Q');

	// Need print out of invalid menu selection

	return 0;
}









