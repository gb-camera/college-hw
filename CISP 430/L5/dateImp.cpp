//dateImp.cpp / dateType implementation file
//Edited to extend functionality of the class
//Michael Dinh - Lab 5 - CISP 430 - Huang (Spring 2020)

#include <iostream>
#include "date.h"

using namespace std;

void dateType::setDate(int month, int day, int year) {
    //This function is fine as is
    if (year >= 1)
		dYear = year;
    else
		dYear = 1900;

    if (1 <= month && month <= 12)
		dMonth = month;
    else
		dMonth = 1;

    switch (dMonth)
    {
    case 1: 
    case 3: 
    case 5: 
    case 7:
	case 8: 
    case 10: 
    case 12:
        if (1 <= day && day <= 31)
            dDay = day;
        else
            dDay = 1;
        break;
    case 4: 
    case 6: 
    case 9: 
    case 11: 
        if (1 <= day && day <= 30)
            dDay = day;
        else
            dDay = 1;
        break;
    case 2: 
        if (isLeapYear())
        {
            if (1 <= day && day <= 29)
                dDay = day;
            else
                dDay = 1;
        }
        else
        {
            if (1 <= day && day <= 28)
                dDay = day;
            else
                dDay = 1;
        }
    }
}

void dateType::getDate(int& month, int& day, int& year) {
    //This function is fine as is
    month = dMonth;
    day = dDay;
    year = dYear;
}

void dateType::print() const {
    //This function was renamed, but was otherwise fine as is
    cout << dMonth << "-" << dDay << "-" << dYear;
}

dateType::dateType(int month, int day, int year) { //constructor with parameter
    //This function is fine as is
    setDate(month, day, year);	
}

bool dateType::isLeapYear() {
    //This function is also fine as is
    if ((dYear % 4 == 0 && dYear % 100 != 0) || (dYear % 400 == 0))
        return true;
    else 
        return false;
}

//New functions are as follows
void dateType::setMonth(int month) {
    //Check if the month is valid
    //The following code was lifted from setDate
    if (1 <= month && month <= 12) //Month must be between 1 and 12 inclusive
        dMonth = month;
    else
        dMonth = 1; //Otherwise we set dMonth to 1 like in setDate
}

void dateType::setDay(int day) {
    //We need to check if the day is valid
    //Since validity of the day value is dependant on the month, use a switch case
    //The following code was lifted from setDate
    switch (dMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: //Cases where 1 to 31 is valid are in Jan, Mar, May, July, Aug, Oct, Dec.
        if (1 <= day && day <= 31)
            dDay = day;
        else
            dDay = 1;
        break;
    case 4:
    case 6:
    case 9:
    case 11: //Cases where only 1 to 30 is valid are in Apr, Jun, Sep, Nov.
        if (1 <= day && day <= 30)
            dDay = day;
        else
            dDay = 1;
        break;
    case 2: //February is the leap year month
        //We need to check if the current dYear is a leap year
        if (isLeapYear()) { //If it is a leap year, day is valid from 1 to 29
            if (1 <= day && day <= 29)
                dDay = day;
            else
                dDay = 1;
        }
        else { //Otherwise it's only valid from 1 to 28
            if (1 <= day && day <= 28)
                dDay = day;
            else
                dDay = 1;
        }
    }
    //In all cases, if day is not valid, dDay will default to 1 just like in setDate
}

void dateType::setYear(int year) {
    //Check if year is valid
    //The following code was lifted from setDate
    if (year >= 1) //The year only has to be greater than or equal to 1 to be valid
        dYear = year;
    else //Otherwise it defaults to 1990 just like in setDate
        dYear = 1900;
}

int dateType::getMonth() {
    //We only need to return the month here
    return dMonth;
}

int dateType::getDay() {
    //We only need to return the day here
    return dDay;
}

int dateType::getYear() {
    //We only need to return the year here
    return dYear;
}

int dateType::getDaysInMonth() {
    //We want this function to return the TOTAL number of days in the date's given month
    //Once again, use a switch
    switch (dMonth) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: //These are the months with 31 days
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11: //These are the months with 30 days
        return 30;
        break;
    case 2: //Leap year month, act accordingly
        if (isLeapYear()) { return 29; }
        else { return 28; }
        break;
    default: //Default for errors
        cout << "Error in getDaysInMonth function!" << endl;
        return 0;
    }
}

int dateType::numberOfDaysPassed() {
    //We want this function to return the TOTAL number of days PASSED in the year, i.e. from 1-1 to the date given
    //Create a variable to keep track of the total number of days
    int totalDays = 0;
    //Since we want to keep a sum of days per month, we should use an array
    int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    //Check the leap year and modify values as appropriate
    if (isLeapYear()) { monthDays[2] = 29; }
    //Use a loop to add days
    for (int i = 0; i < dMonth; ++i) {
        totalDays += monthDays[i];
    }
    //Then add the number of days in the date to the sum
    totalDays += dDay;
    return totalDays;
}

int dateType::numberOfDaysLeft() {
    //We want this function to return the TOTAL number of days LEFT in the year, i.e. from the date given to 12-31
    //Create a variable that acts as the total number of days in the year, depending on if it's a leap year
    int totalDays;
    if (isLeapYear()) { totalDays = 366; }
    else { totalDays = 365; }
    //We can use numberOfDaysPassed to simplify this process by subtracting its' result from the total number of days
    totalDays -= numberOfDaysPassed();
    return totalDays;
}

void dateType::incrementDate(int days) {
    //We want this function to advance the date by the given number of days
    //Once again, use an array to keep track of days in months
    int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < days; i++){ //Loop until all days are added
        dDay++; //Add days normally
        //We should reset the days value back to 1 and add another month if we hit a new month
        //This is either when the days value is bigger than the associated value for the month,
        //or when we hit 2/29 and it isn't a leap year
        if (dDay > monthDays[dMonth] || (dMonth == 2 && dDay == 29 && !isLeapYear())){
            dDay = 1;
            dMonth++;
            if (dMonth == 13){ //If we hit a new year, we should reset the months back to 1 and add a year.
                dMonth = 1;
                dYear++;
            }
        }
    }
}