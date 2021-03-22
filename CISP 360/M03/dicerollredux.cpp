#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //Configure rand() to predefined seed
    srand(1701);

    //Declare variables
    int numDice;
    int sideDice;
    char midPart;
    bool validNum;
    bool validMid;
    bool validSide;

    int rollOne = 0;
    int rollTwo = 0;
    int rollThree = 0;
    int rollSum = 0;

    //Prompt for designation, read input
    cout << "Choose 1, 2, or 3 dice (6-, 10-, 12-, or 20-sided)" << endl;
    cout << "Enter designation (e.g. '2d6'): " << endl;
    cin  >> numDice >> midPart >> sideDice;
    
    //Validate input
    //midPart input check
    if (midPart == 'd') {
        validMid = true;
    }
    else {
        validMid = false;
    }
    //numDice input check
    switch (numDice) {
        //Valid for cases 1 to 3
        case 1:
        case 2:
        case 3: {
            validNum = true;
            break;
        }
        //Invalid for all other cases
        default: {
            validNum = false;
            break;
        }
    }
    //sideDice input check
    switch (sideDice) {
        //Valid for case 6, 10, 12, and 20
        case 6:
        case 10:
        case 12:
        case 20: {
            validSide = true;
            break;
        }
        //Invalid for all other cases
        default: {
            validSide = false;
            break;
        }
    }
    //General validity check
    if (!validNum || !validMid || !validSide) {
        cout << "Not a valid designation" << endl;
    }
    //If all valid, program runs
    else {
        switch (numDice) {
            //1 die
            case 1: {
                rollOne = (rand() % sideDice) + 1;
                cout << numDice << "d" << sideDice << " result: " << rollOne << endl;
                rollOne = (rand() % sideDice) + 1;
                cout << numDice << "d" << sideDice << " result: " << rollOne << endl;
                rollOne = (rand() % sideDice) + 1;
                cout << numDice << "d" << sideDice << " result: " << rollOne << endl;
                break;
            }
            //2 dice
            case 2: {
                rollOne = (rand() % sideDice) + 1;
                rollTwo = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;
                rollOne = (rand() % sideDice) + 1;
                rollTwo = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;
                rollOne = (rand() % sideDice) + 1;
                rollTwo = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " = " << rollSum << endl;
                break;
            }
            //3 dice
            case 3: {
                rollOne   = (rand() % sideDice) + 1;
                rollTwo   = (rand() % sideDice) + 1;
                rollThree = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo + rollThree;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " + " << rollThree << " = " << rollSum << endl;
                rollOne   = (rand() % sideDice) + 1;
                rollTwo   = (rand() % sideDice) + 1;
                rollThree = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo + rollThree;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " + " << rollThree << " = " << rollSum << endl;
                rollOne   = (rand() % sideDice) + 1;
                rollTwo   = (rand() % sideDice) + 1;
                rollThree = (rand() % sideDice) + 1;
                rollSum = rollOne + rollTwo + rollThree;
                cout << numDice << "d" << sideDice << " result: " << rollOne << " + " << rollTwo << " + " << rollThree << " = " << rollSum << endl;
                break;
            }
            //Default for error purposes
            default: {
                cout << "Error!" << endl;
                break;
            }
        }
    }
    return 0;
}
