//Implementation file date
//Modifed to include isLeapYear and data validity checks
//Michael Dinh - CISP 430 - Huang (Spring 2020)

#include <iostream> //For program output
#include "date.h" //For function definitions
using namespace std;

void dateType::setDate(int month, int day, int year) {
    //Year data check
    if (year > 0) { //Simply check if the year is greater than 0
        dYear = year;
    }
    else {
        dYear = 1900;
    }
    //Month data check
    if ((month > 0) & (month < 13)) { //Simply check if the month is within the valid range of months (1 to 12)
        dMonth = month;
    }
    else {
        dMonth = 1;
    }
    //Day data check
    //Since this is dependent on the month, use a switch
    switch (month) {
        case 2: { //Start with February first since it's the leap year month
            //Check for leap year in the date
            if (isLeapYear(year)) { //If it IS a leap year date...
                if ((day > 0) & (day < 30)) { ///then possible values should be 1 to 29
                    dDay = day;
                }
                else {
                    dDay = 1;
                }
            }
            else { //If it ISN'T a leap year date...
                if ((day > 0) & (day < 29)) { //then possible values should be 1 to 28
                    dDay = day;
                }
                else {
                    dDay = 1;
                }
            }
            break;
        }
        //Now we can deal with the regular months; since all of the remaining
        //months have similar operation, we can let the flow of command fall to
        //the lase case for each subset of months.
        //30 day months
        case 4: //April
        case 6: //June
        case 9: //September
        case 11: { //November
            if ((day > 0) & (day < 31)) { //Possible values should be 1 to 30
                dDay = day;
            }
            else {
                dDay = 1;
            }
            break;
        }
        //31 day months
        case 1: //January
        case 3: //March
        case 5: //May
        case 7: //July
        case 8: //August
        case 10: //October
        case 12: { //December
            if ((day > 0) & (day < 32)) { //Possible values should be 1 to 31
                dDay = day;
            }
            else {
                dDay = 1;
            }
            break;
        }
        default: { //Default case, just in case ;)
            dDay = 1;
            break;
        }
    }
}

bool dateType::isLeapYear(int year) const {
    //See http://scienceworld.wolfram.com/astronomy/LeapYear.html
    //for information on leap years used for this function's implementation.
    if (year % 4 == 0) { //Leap years must be divisible by four
        if (year % 100 == 0) { //Leap years must NOT be divisible by 100...
            if (year % 400 == 0) { //...except for those years which are divisible by 400
                return true; //If all three conditions are satisfied, return true
            }
            else {
                return false; //If a leap year is divisible by 100 and not 400, return false
            }
        }
        else {
            return true; //If a leap year is divisible by 4 and not 100, return true
        }
    }
    else {
        return false; //If a leap year is not divisible by 4, return false
    }
}

//Constructor with parameters
//The constructor should work without modification since the data check
//was implemented in the setDate function, which the constructor is dependent on.
dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

int dateType::getDay() const {
    return dDay;
}

int dateType::getMonth() const {
    return dMonth;
}

int dateType::getYear() const {
    return dYear;
}

void dateType::printDate() const {
    cout << dMonth << "-" << dDay << "-" << dYear;
}