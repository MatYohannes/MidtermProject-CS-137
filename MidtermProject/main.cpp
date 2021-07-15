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

		cout << "COURSE ENTRY MENU FOR:	  " << currentSemester.getName() << " (" << currentSemester.getStartOf() << " - " << currentSemester.getEndOf() << ")" << endl;
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
			double unitsValue;

			if (personCourseSchedule.getNumCourses() != personCourseSchedule.getMaxSize())
			{
				// Asking for class number, class name, class meeting days and class unit
				cout << "\nEntering a new course selected\n";
				cout << "----------------------------------" << endl;
				cin.ignore();
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
				cout << "Please enter the ending time for the course in this format:   7:30 PM\n";
				cin >> classEndTime;

				// Asking for start and end date
				Date classStartDate;
				cout << "Please enter the start date for the course in this format: 7/4/2021 \n";
				cin >> classStartDate;
				Date classEndDate;
				cout << "Please enter the end date for the course in this format: 7/4/2021 \n";
				cin >> classEndDate;

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
				cout << "Please type in the course number you would like to remove from the course schedule: ";
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

		if (choice != '1' || choice != '2' || choice != '3' || choice != 'q' || choice != 'Q')
		{
			cout << "Invalid selection!\n" << endl;
		}

	} while (choice != 'q' && choice != 'Q');

	// Need print out of invalid menu selection

	return 0;
}




