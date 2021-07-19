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
	cout << "Welcome to the Imaginary College of the future!!" << endl;

	// Asking for name, semester name, semester start day, semester end day, number of classes taking
	string personName;
	cout << "Please enter your name: ";
	getline(cin, personName);
	string personSemester;
	cout << "Please enter the semester you are joining in this format: Fall 2019 \n";
	getline(cin, personSemester);

	bool dayStatus = false;
	Date personStartDate;
	Date personEndDate;
	do
	{
		cout << "Please enter the start date of semester is this format: 7/4/2021 \n";
		cin >> personStartDate;
		cout << "Please enter the end date of semester is this format: 7/4/2021 \n";
		cin >> personEndDate;
		dayStatus = false;

		if (personStartDate > personEndDate)
		{
			cout << "\nThe semester can not end before it starts. Please input correct dates.\n" << endl;
			dayStatus = true;
		}

	} while (dayStatus);
	
	int numOfClasses;

	while (cout << "How many classes do you plan to take? " && !(cin >> numOfClasses))
	{
		cin.clear();
		cin.ignore(numeric_limits < streamsize>::max(), '\n');
		cout << "\nInvalid input. Please re-enter a number.\n" << endl;
	}

	// Creating Semester and Course Schedule objects
	Semester currentSemester(personSemester, personStartDate, personEndDate);
	CourseSchedule personCourseSchedule(personName, currentSemester, numOfClasses);

	// Menu
	char choice;
	do {
		cout << "\nCOURSE ENTRY MENU FOR:	  " << currentSemester.getName() << " (" << currentSemester.getStartOf() << " - " << currentSemester.getEndOf() << ")" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1) Enter a new course\n";
		cout << "2) Remove a course\n";
		cout << "3) Print a Semester Schedule\n";
		cout << "q) Quit the program" << endl;

		cout << "\nPlease enter your choice?" << endl;
		cin >> choice;

		if (choice == '1')
		{
			string classNumber;
			string className;
			string classDays;
			double unitsValue;

			if (personCourseSchedule.getNumCourses() != personCourseSchedule.getMaxSize())
			{
				// Asking for class number, class name, class meeting days and class unit
				cout << "\nEntering a new course selected\n";
				cout << "----------------------------------" << endl;
				cin.ignore();
				cout << "Please provide a course number in this format - CSIS 137: ";
				getline(cin, classNumber);
				cout << "Please provide a course name in this format - C++: ";
				getline(cin, className);
				cout << "Please provide the meeting days for the course: ";
				getline(cin, classDays);

				while (cout << "Please provide the number of units the course is worth: " && !(cin >> unitsValue))
				{
					cin.clear();
					cin.ignore(numeric_limits < streamsize>::max(), '\n');
					cout << "\nInvalid input. Please re-enter a number.\n" << endl;
				}

				// Asking for start and end time
				Time classStartTime;
				Time classEndTime;
				bool classTimeStatus = false;

				do
				{
					cout << "Please enter the starting time for the course in this format:   7:30 PM\n";
					cin >> classStartTime;
					cout << "Please enter the ending time for the course in this format:   7:30 PM\n";
					cin >> classEndTime;
					classTimeStatus = false;

					if (classStartTime > classEndTime)
					{
						cout << "\nThe class can not end before it starts. Please input correct times.\n" << endl;
						classTimeStatus = true;
					}

				} while (classTimeStatus);
				
				// Asking for start and end date
				Date classStartDate;
				Date classEndDate;
				bool classDayStatus = false;

				do
				{
					cout << "Please enter the start date for the course in this format: 7/4/2021 \n";
					cin >> classStartDate;
					cout << "Please enter the end date for the course in this format: 7/4/2021 \n";
					cin >> classEndDate;
					classDayStatus = false;

					if (classStartDate > classEndDate)
					{
						cout << "\nThe course can not end before it starts. Please input correct dates.\n" << endl;
						classDayStatus = true;
					}

				} while (classDayStatus);

				Course courseToAdd(className, classNumber, classDays, unitsValue, classStartDate, classEndDate, classStartTime, classEndTime);

				// Adding course1 to user course schedule
				personCourseSchedule.addCourse(courseToAdd);	
			}
			else
			{
				cout << "Your plate is full. You can not add another class to the course schedule\n" << endl;
			}
		}
		
		if (choice == '2')
		{
			if (personCourseSchedule.getNumCourses() != 0)
			{
				string removeClass;
				cout << "Please type in the course number you would like to remove from the course schedule in format - CSIS 137: ";
				cin.ignore();
				getline(cin, removeClass);
				personCourseSchedule.removeCourse(removeClass);
				cout << endl;
				Course courseToRemove;
			}
			else
			{
				cout << "You have no class to remove.\n" << endl;
			}
		}

		if (choice == '3')
		{
			cout << personCourseSchedule;
		}

		if (choice != '1' && choice != '2' && choice != '3' && choice != 'q' && choice != 'Q')
		{
			cout << "Invalid selection!\n" << endl;
		}

	} while (choice != 'q' && choice != 'Q');

	// Need print out of invalid menu selection

	return 0;
}

