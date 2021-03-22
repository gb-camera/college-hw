#include <iostream>
#include <random>

using namespace std;

int main() {
    srand(32767);

    cout << "Enter dice throw designators..." << endl
         << " # dice: 1 to 8, # sides: 4, 6, 8, 10, 12" << endl
         << " e.g. '2d6', or '0' to quit" << endl;

    int nDice, nSides, roll;
    int sum = 0;
    char ch;

    //"Forever" Loop
    while (true) {
        cout << "> ";
        cin >> nDice >> ch >> nSides;
        if (nDice == 0) {
            // User signal to end the prgram
            break;
        }
        cout << endl;
        //Validate input (skip if bad)
        if(nDice < 0 || nDice > 8 || ch != 'd') {
            cout << "Invalid Designator" << endl;
            continue;
        }
        else if(nSides != 4 && nSides != 6 && nSides != 8 && nSides != 10 && nSides != 12) {
            cout << "Invalid Designator" << endl;
            continue;
        }
        //Start the output (e.g. "2d6 result: ")
        cout << nDice << ch << nSides << " result: ";
        //Throw dice and sum/display the result
        sum = 0;
        for(int count = 1; count <= nDice; count++) {
            roll = (rand() % nSides) + 1;
            sum += roll;
            if(count < nDice) {
                cout << roll << " + ";
            }
            else {
                cout << roll << " = " << sum << endl;
            }
        }
    }
    return 0;
}