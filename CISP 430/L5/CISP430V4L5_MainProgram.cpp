//dateType testing program
//Tests the class according to the specificiations of the lab assignment
//Michael Dinh - Lab 5 - CISP 430 - Huang (Spring 2020)

#include "date.h"
#include <iostream>
using namespace std;

int main(){
	//We need to make two date objects: one with date 3/15/2017, and one with date 15/20/2018
	//Instanciate both objects
	dateType date1(3, 15, 2017);
	dateType date2(115, 20, 2018);
	
	//First rung of testing is for date 1
	//First call the print function on date 1
	cout << "Date 1: ";
	date1.print();
	cout << endl;

	//Then call numberOfDaysPassed()
	cout << " Number of days passed for date 1 is " << date1.numberOfDaysPassed() << ".\n";
	//Then call numberOfDaysLeft()
	cout << " Number of days left for date 1 is " << date1.numberOfDaysLeft() << ".\n";
	//Then call getDaysInMonth()
	cout << " The number of days in date 1's month is " << date1.getDaysInMonth() << ".\n";
	
	//Call incrementDate to increment by 41 days
	cout << " Adding 41 days to date 1; the new date 1 is ";
	date1.incrementDate(41);
	date1.print();
	cout << ".\n";
	//Recall getDaysInMonth()
	cout << " The number of days in date 1's new month is " << date1.getDaysInMonth() << ".\n";
	
	cout << endl << "*******************************************" << endl << endl;

	//Second rung of testing is for date 2
	//First call the print function on date 2
	cout << "Date 2: ";
	date2.print();
	cout << endl;

	//Call setDate function for 14-40-0 for date 2
	cout << " Calling setDate function to set the month to 14," << endl;
	cout << " the day to 40, and the year to 0 for date 2." << endl;
	date2.setDate(14, 40, 0);
	//Print date 2 again
	cout << " Date 2's new information is: ";
	date2.print();
	cout << ".\n" << endl;

	//Call each individual setter function for date 2 for 2-31-2019
	cout << " Calling setYear, setMonth, and setDay functions" << endl;
	cout << " of date 2 to set the year to 2019, the month to" << endl;
	cout << " 2, and the day to 31.\n" << endl;
	date2.setYear(2019);
	date2.setMonth(2);
	date1.setDay(31);

	//Call each individual getter function for date 2
	cout << " Calling getYear, getMonth, and getDay functions" << endl;
	cout << " to display the date for date 2.\n" << endl;
	cout << " Date 2's new information is: " << endl;
	cout << " The month is " << date2.getMonth() << ".\n";
	cout << " The day is " << date2.getDay() << ".\n";
	cout << " The year is " << date2.getYear() << ".\n";

	system("pause");
	return 0;
}