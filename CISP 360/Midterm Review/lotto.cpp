#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void randArray(int a[], const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        a[i] = rand() % 10;
    }
}

void inputArray(int a[], const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        cout << "Enter a number between 0 to 9 inclusive: ";
        cin >> a[i];
        while(a[i] > 9 || a[i] < 0) {
            cout << "Invalid input." << endl << "Enter a number between 0 and 9 inclusive. ";
            cin >> a[i];
        }
    }
}

void showArray(int a[], const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        if(i == SIZE - 1) {
            cout << a[i] << endl;
        }
        else {
            cout << a[i] << " ";
        }
    }
}

int countMatches(int a[], int b[], const int SIZE) {
    int count = 0;
    for(int i = 0; i < SIZE; i++) {
        if (a[i] == b[i]) {
            count += 1;
        }
        else {
            continue;
        }
    }
    return count;
}

int main() {
    const int SIZE = 5;
    int lottoVals[SIZE], userVals[SIZE], count;
    char choice;
    cout << "Do you want to play lottery? Type y/n: ";
    cin >> choice;
    while(choice == 'y' || choice == 'Y') {
        inputArray(userVals, SIZE);
        randArray(lottoVals, SIZE);
        count = countMatches(userVals, lottoVals, SIZE);
        cout << endl << "Lottery Picks: ";
        showArray(lottoVals, SIZE);
        cout << "Your numbers: ";
        showArray(userVals, SIZE);
        cout << "Matches: " << count << endl;
        if(count == SIZE) {
            cout << "You're a winner!" << endl;
        }
        else {
            cout << "Better luck next time!" << endl;
        }
        cout << "Do you want to play lottery again? Type y/n: ";
        cin >> choice;
    }
}