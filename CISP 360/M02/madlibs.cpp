#include <iostream>
#include <string>
using namespace std;

int main() {
    //Declare all string variables
    string location;
    string verb1;
    string verb2;
    string adjective;
    string adverb;
    string noun;
    string relative;
    cout << "\n** MADLIBS **\n";
    
    //User input
    cout << "Enter a location (e.g. \"the living room\"): "; 
    getline(cin, location);
    cout << "Enter a verb (e.g. \"sing\"): ";
    cin  >> verb1;
    cout << "Enter another verb: ";
    cin  >> verb2;
    cout << "Enter an adjective (e.g. \"greedy\"): ";
    cin  >> adjective;
    cout << "Enter an adverb (e.g. \"noisily\"): ";
    cin  >> adverb;
    cin.ignore();
    cout << "Enter a noun (e.g. \"peanut\"): ";
    getline(cin, noun);
    cout << "Enter a relative (e.g. \"aunt\"): ";
    getline(cin, relative);

    //Output
    cout << "My " << adjective << " " << relative << " is convinced that if I " << verb1 << " " << adverb << "," << endl;
    cout << "I will be able to " << verb2 << " the " << noun << " in " << location << ".\n";
    return 0;
}
