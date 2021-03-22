#include <iostream>
#include <string>
using namespace std;
int main() {
    //Variable declaration space
    string fizzWord = "A";
    string buzzWord = "A";
    int fizzNum = 0;
    int buzzNum = 0;

    //Output program title
    cout << "== Fizz Buzz Deluxe ==" << endl;

    //Input / validate a pair of words
    while(fizzWord.size() > 6 || fizzWord.size() < 3 || buzzWord.size() > 6 || buzzWord.size() < 3 || fizzWord == buzzWord) {
        cout << "Enter a pair of words (each from 3-6 chars long): ";
        cin  >> fizzWord >> buzzWord;
    }
    //Input / validate a pair of divisors
    while(fizzNum < 2 || fizzNum > 15 || buzzNum < 2 || buzzNum > 15 || fizzNum == buzzNum) {
        cout << "Enter two different integers (between 2 and 15): ";
        cin  >> fizzNum >> buzzNum;
    }
    //Output "fizz buzz" sequence from 1 to 100
    cout << endl;
    for(int count = 1; count <= 100; count++) {
        if (count % 10 == 0 && count % fizzNum == 0 && count % buzzNum == 0) {
            cout << " " << fizzWord << buzzWord << endl;
            continue;
        }
        else if (count % 10 == 0 && count % fizzNum == 0) {
            cout << " " << fizzWord << endl;
            continue;
        }
        else if (count % 10 == 0 && count % buzzNum == 0) {
            cout << " " << buzzWord << endl;
            continue;
        }
        else if (count % 10 == 0) {
            cout << " " << count << endl;
            continue;
        }
        else if (count % fizzNum == 0 && count % buzzNum == 0) {
            cout << " " << fizzWord << buzzWord;
            continue;
        }
        else if (count % fizzNum == 0) {
            cout << " " << fizzWord;
            continue;
        }
        else if (count % buzzNum == 0) {
            cout << " " << buzzWord;
            continue;
        }
        else {
            cout << " " << count;
            continue;
        }
    }

    //Output "fizz buzz" symbol map
    cout << endl;
    for(int count = 1; count <= 100; count++) {
        if (count % 10 == 0 && count % fizzNum == 0 && count % buzzNum == 0) {
            cout << " #" << endl;
            continue;
        }
        else if (count % 10 == 0 && count % fizzNum == 0) {
            cout << " " << "+" << endl;
            continue;
        }
        else if (count % 10 == 0 && count % buzzNum == 0) {
            cout << " " << "*" << endl;
            continue;
        }
        else if (count % 10 == 0) {
            cout << " " << "." << endl;
            continue;
        }
        else if (count % fizzNum == 0 && count % buzzNum == 0) {
            cout << " " << "#";
            continue;
        }
        else if (count % fizzNum == 0) {
            cout << " " << "+";
            continue;
        }
        else if (count % buzzNum == 0) {
            cout << " " << "*";
            continue;
        }
        else {
            cout << " " << ".";
            continue;
        }
    }
    return 0;
}