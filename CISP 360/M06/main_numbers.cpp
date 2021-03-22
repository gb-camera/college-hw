#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
//Define useful constants (widths, file name)
const string FILE_NAME = "number-table.txt";
const int WIDTH_123 = 10;
const int WIDTH_4 = 15;

int main() {
    //Declare local variables
    int start, stop, step;
    int errorVal = 0;
    ofstream fileOut;

    //Acquire start, stop, and step values from user (validated, use a while loop while numbers are not valid)
    cout << "Enter start, stop, and step values (space separated): ";
    cin  >> start >> stop >> step;
    cout << endl;
    while(start > stop) {
        cout << "Oops! stop value must be greater than start value.\n";
        cout << "Enter start, stop, and step values (space separated): ";
        cin  >> start >> stop >> step;
        cout << endl;
    }
    while(step <= 0) {
        cout << "Oops! step value must be greater than 0.\n";
        cout << "Enter start, stop, and step values (space separated): ";
        cin  >> start >> stop >> step;
        cout << endl;
    }
    while(((stop - start) / step + 1) > 50) {
        cout << "Oops! number of iterations should not exceed 50.\n";
        cout << "Enter start, stop, and step values (space separated): ";
        cin  >> start >> stop >> step;
        cout << endl;
    }
    
    //Open output file for write (check-for / handle error)
    fileOut.open(FILE_NAME);
    if(!fileOut.is_open()) {
        errorVal = 1;
    }
    
    //Write table header to file
    fileOut << "---------------------------------------------\n";
    fileOut << "    Number   Squared     Cubed    Square-Root\n";
    fileOut << "---------------------------------------------\n";

    //Construct `for` loop. For each iteration...
    for(int i = start; i <= stop; i = i + step) {
        //Write a row of the table to the file 
        int squared, cubed;
        double squareRoot;
        squared = i * i;
        cubed = i * i * i;
        squareRoot = sqrt(i);
        fileOut << setw(WIDTH_123) << i;
        fileOut << setw(WIDTH_123) << squared;
        fileOut << setw(WIDTH_123) << cubed;
        fileOut << setw(WIDTH_4) << fixed << setprecision(8) << squareRoot << endl;
    }
    
    //Finish off the table with a dashed line
    fileOut << "---------------------------------------------\n";
    
    //Close the file and write a message to `cout`
    fileOut.close();
    cout << "Table written to number-table.txt\n";
    
    //Return error status number
    return errorVal;
}
