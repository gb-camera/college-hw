#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Note that `#include <cstdlib>` is required for using rand(), srand().
    srand(2019);    // *** do NOT change this seed ***
    // Note that in a production version of the program, something like
    //  `srand(time(0))` would be used to set an initial seed based on the
    //  system clock, thus "randomizing" the number sequence.

    // Declare variables
    int diceSides = 0;
    int rollOne = 0;
    int rollTwo = 0;
    int rollSum = 0;

    // Prompt user for number of sides
    cout << "Number of sides (4, 6, 8, 10, 12, or 20): ";
    cin  >> diceSides;

    // Generate and print the result of roll one
    rollOne = (rand() % diceSides) + 1;
    rollTwo = (rand() % diceSides) + 1;
    rollSum = rollOne + rollTwo;
    cout << "2d" << diceSides << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;

    // Generate and print the result of roll two
    rollOne = (rand() % diceSides) + 1;
    rollTwo = (rand() % diceSides) + 1;
    rollSum = rollOne + rollTwo;
    cout << "2d" << diceSides << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;

    // Generate and print the result of roll three
    rollOne = (rand() % diceSides) + 1;
    rollTwo = (rand() % diceSides) + 1;
    rollSum = rollOne + rollTwo;
    cout << "2d" << diceSides << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;

    return 0;
}
