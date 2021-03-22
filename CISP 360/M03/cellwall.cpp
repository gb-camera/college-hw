#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

using namespace std;

int main() {
    const int R_SEED = 314159;
    const double EPSILON = 0.0001;
    //Declare calculation variables
    bool choiceValid;
    double distance = 99.99;

    //Declare variables for user input
    char choice = 'a';
    double x;
    double y;

    //Configure rand with R_SEED, configure 'cout' to output decimal values to 2 decimal places
    cout << setprecision(2) << fixed << showpoint;
    srand(R_SEED);

    //Prompt the user with selection choices
    cout << "Select particle location by:\n";
    cout << "\t[E] entering coordinates\n";
    cout << "\t[R] random generation\n";
    
    //Read in user choice
    cin >> choice;

    //Use a switch statement to set x and y values
    switch (choice) {
        // E case: Prompt / read in user x and y
        case 'E':
        case 'e': {
            cout << "Enter X-coordinate: ";
            cin  >> x;
            cout << "Enter Y-coordinate: ";
            cin  >> y;
            choiceValid = true;
            break;
        }
        // R case: Randomize x and y from range [-12, 12]
        case 'R':
        case 'r': {
            x = rand() % 25 - 12;
            y = rand() % 25 - 12;
            choiceValid = true;
            break;
        }
        //Default case: Invalid choice
        default: {
            choiceValid = false;
        }
    }
    //If valid choice selected, perform computations
    if (choiceValid) {
        //Display particle location
        cout << "Particle is at (" << x << "," << y << ")\n";
        //Compute particle distance from origin
        distance = sqrt(pow(x,2) + pow(y,2));
        //Check distance for status of particle relative to cell wall
            if (fabs(distance - 10.0) < EPSILON) {
                cout << "On cell wall" << endl;
            }
            else if (distance > 10.0) {
                cout << "Outside cell wall" << endl;
            }
            else {
                cout << "Inside cell wall" << endl;
            }
    }
    else {
        cout << "Unknown option: " << choice << endl;
    }
    return 0;
}   