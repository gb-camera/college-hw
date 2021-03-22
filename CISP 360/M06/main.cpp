#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Declare local variables
    ifstream fileInput;
    ofstream fileoutputEven;
    ofstream fileoutputOdd;
    string fileName = "AAAAAA";
    string fileoutEven = "-even.txt";
    string fileoutOdd = "-odd.txt";
    string fileInputted;

    //Acquire input filename (validated)
    cout << "Enter the name of the input file: ";
    cin  >> fileName;
    while(fileName.find(".txt") == string::npos) {
        cout << endl << "Only filenames ending in '.txt' are accepted!\n";
        cout << "Enter the name of the input file: ";
        cin  >> fileName;
    }
    cout << endl;
    //Open input file (abort if failure)
    fileInput.open(fileName);
    if(!fileInput.is_open()) {
        cout << "Failed to open file for read: " << fileName << endl;
        return 1;
    }
    //Generate output file names and open output files (check there were no errors, abort if failure)
    fileoutEven.insert(0, fileName.substr(0, fileName.length() - 4));
    fileoutOdd.insert(0, fileName.substr(0, fileName.length() - 4));
    fileoutputEven.open(fileoutEven);
    fileoutputOdd.open(fileoutOdd);
    if(!fileoutputEven.is_open() || !fileoutputOdd.is_open()) {
        cout << "Error with the file creation!";
        return 1;
    }
    //Initialize word counts
    int evenCount = 0;
    int oddCount = 0;
    int totalCount = 0;
    //Use a `while` loop to read in / test / output each word
    fileInput >> fileInputted;
    while(!fileInput.fail()) {
        totalCount += 1;
        if(fileInputted.length() % 2 == 0) {
            evenCount += 1;
            fileoutputEven << fileInputted << endl;
        }
        else if(fileInputted.length() % 2 == 1) {
            oddCount += 1;
            fileoutputOdd << fileInputted << endl;
        }
        fileInput >> fileInputted;
    }
    //Close all files
    fileInput.close();
    fileoutputEven.close();
    fileoutputOdd.close();
    //Output summary
    cout << totalCount << " words read in from " << fileName << endl;
    cout << evenCount << " words written to " << fileoutEven << endl;
    cout << oddCount << " words written to " << fileoutOdd << endl;
    return 0;
}