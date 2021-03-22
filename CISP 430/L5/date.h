#ifndef date_H
#define date_H

//date.h / dateType header file
//Edited to extend functionality of the class
//Michael Dinh - Lab 5 - CISP 430 - Huang (Spring 2020)

class dateType
{
public:
    void setDate(int month, int day, int year);
      //Function to set the date
      //Data members dMonth, dDay, and dYear are set 
      //according to the parameters
      //Postcondition: dMonth = month; dDay = day;
      //    dYear = year

    void getDate(int& month, int& day, int& year);
      //Function to return the date
      //Postcondition: month = dMonth; day = dDay;
      //    year = dYear;

	bool isLeapYear(); 
      //Function to check if a year is a leap year
      //Return true if a year is a leap year, false otherwise

    void print() const;
      //Function to output the date in the form mm-dd-yyyy.
	  //NOTE: Function name has been modified according to
	  //assignment specification.

    dateType(int month = 1, int day = 1, int year = 1900);
      //Constructor to set the date
      //Data members dMonth, dDay, and dYear are set 
      //according to the parameters
      //Postcondition: dMonth = month; dDay = day; 
      //    dYear = year
      //If no values are specified, the default values are 
      //used to initialize the data members.
	  
	//Following are public members added for the assignment.
	
	void setMonth(int month);
		//Function that sets the month.
		//Postcondition: dMonth will equal month if month is valid.
		
	void setDay(int day);
		//Function that sets the day.
		//Postcondition: dDay will equal day if day is valid.
		
	void setYear(int year);
		//Function that sets the year.
		//Postcondition: dYear will equal year if year is valid.
		
	int getMonth();
		//Function that returns the month.
		
	int getDay();
		//Function that returns the day.
		
	int getYear();
		//Function that returns the year.
			
	int getDaysInMonth();
		//Function that returns the number of days in the
		//month of a given date.
	
	int numberOfDaysPassed();
		//Function that returns the number of days passed
		//in the year of a given date.
		
	int numberOfDaysLeft();
		//Function that returns the number of days left in
		//the year of a given date.
		
	void incrementDate(int days);
		//Function that advances a date by the given number
		//of days.

private:
    int dMonth;	//variable to store month
    int dDay;   //variable to store day
    int dYear;  //variable to store year
};

#endif