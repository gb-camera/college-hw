#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
//Declare useful contents (file name template, widths, min and max table size)
const string FILE_NAME_TEMP = "times-table-<n>.txt";
const int NUM_WIDTH = 4;
const int MIN = 1;
const int MAX = 12;

int main() {
    //Declare local variables
    int tableSize;
    ofstream fileOut;
    string fileName;
    //Obtain (validated with a while loop) table size from user
    cout << "Enter the table size (from 1 to 12): ";
    cin  >> tableSize;
    while(tableSize > MAX || tableSize < MIN) {
        cout << "Enter the table size (from 1 to 12): ";
        cin  >> tableSize;
    }
    cout << endl;
    //Generate the filename
    fileName = FILE_NAME_TEMP;
    fileName.replace(fileName.find("<n>"), 3, to_string(tableSize));
    //Open output file for write (abort, if an error occurs)
    fileOut.open(fileName);
    if(!fileOut.is_open()) {
        abort;
    }
    //Write table column headers
    fileOut << "---+";
    for(int i = 1; i <= tableSize; i++) {
        fileOut << setw(4) << "----";
    }
    fileOut << endl << " x |";
    for(int i = 1; i <= tableSize; i++) {
        fileOut << setw(4) << i;
    }
    fileOut << endl << "---+";
    for(int i = 1; i <= tableSize; i++) {
        fileOut << setw(4) << "----";
    }
    fileOut << endl;
    //Use nested `for` loops to write the main table
    //Outer loop iterates over the rows
    for(int i = 1; i <= tableSize; i++) {
        fileOut << setfill(' ') << setw(2) << i << " |";
        //Inner loop iterates over the columns
        for(int j = 1; j <= tableSize; j++) {
            fileOut << setw(4) << i * j;
        }
        fileOut << endl;
    }
    //Finish off with a final line, and close the file
    fileOut << "---+";
    for(int i = 1; i <= tableSize; i++) {
        fileOut << setw(4) << "----";
    }
    fileOut << endl;
    fileOut.close();
    cout << "Output written to " << fileName << "!\n";
    return 0;
}