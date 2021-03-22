//CISP430V4A6.cpp
//Michael Dinh - CISP 430 - Assignment 6 - Huang (Spring 2020)
//Driver file for chained node table class

//Specifications:
//	Instantiate two tables with 10 fields
//	Display both tables' info
//	Use RNG to generate 70 numbers between 0 - 200 for the tables
//	Display both tables' info
//	Remove all data from the first table
//	Display both tables' info
//	Use overloaded = to assign second table to first
//	Display both tables' info

#include <iostream>
#include "table2.h"
using namespace std;

struct Record { //We need a struct with a key for the class to work
	double data;
	unsigned int key;
};

void tablePrint(table<Record> t1, table<Record> t2) { //Basic function to handle the table printing
	cout << "Total records in the first table: " << t1.size() << endl;
	cout << "Contents of the first table displayed below:" << endl;
	for (int i = 0; i < 10; ++i) {
		t1.print(i);
	}
	cout << "-------------------------------------------" << endl;
	cout << "Total records in the second table: " << t2.size() << endl;
	cout << "Contents of the second table displayed below:" << endl;
	for (int i = 0; i < 10; ++i) {
		t2.print(i);
	}
	cout << "-------------------------------------------" << endl;
}

int main() {
	//Instantiate two tables
	table<Record> t1, t2;
	Record record;
	//Display table info
	cout << "Instantiating two table objects." << endl << endl;
	tablePrint(t1, t2);
	//Generate the numbers for the tables
	cout << endl << "Using a random number generator to generate 70 numbers for the objects." << endl << endl;
	//Data value doesn't matter for the purposes of this exercise
	record.data = 420.69;
	//Loop 70 times for the RNG process
	for (unsigned int i = 0; i < 70; ++i) {
		//Random values between 0 to 200 = rand() % 201
		record.key = rand() % 201;
		//Insert the first random keyed record
		t1.insert(record);
		record.key = rand() % 201;
		//Insert the second random keyed record
		t2.insert(record);
	}
	//Display tables
	tablePrint(t1, t2);
	//Remove the first table's contents
	cout << endl << "Using clear function to clear the first table." << endl << endl;
	t1.clear();
	//Display tables
	tablePrint(t1, t2);
	//Assign t1 = t2
	cout << endl << "Using operator = and demonstrating operator overloading." << endl << endl;
	t1 = t2;
	//Display tables
	tablePrint(t1, t2);

	//Program end
	system("pause");
	return 0;
}