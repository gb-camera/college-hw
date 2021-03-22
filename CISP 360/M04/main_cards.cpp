#include <iostream>
#include <string>
using namespace std;

int main() {
    const string LINE = "--------------------";

    string matchWord = "AAAAAAA";
    string suitName, rankName;
    int track1, track2;
    bool matchFound = false;

    //Prompt user for matchWord; read in the value
    cout << "Enter match word ('.' for match all): ";
    cin  >> matchWord;

    // TODO (4): consider declaring and initializing additional variables

    //Start output with a line
    cout << LINE << endl;

    //Outer loop ..... ///[0...3] 0 => suitName = "Clubs", 1=> suitName = "Hearts", ...
    for(track1 = 0; track1 <= 3; track1++) {
        switch (track1) {
            case 0: {
                suitName = "Clubs";
                break;
            }
            case 1: {
                suitName = "Hearts";
                break;
            }
            case 2: {
                suitName = "Spades";
                break;
            }
            case 3: {
                suitName = "Diamonds";
                break;
            }
            default: {
                suitName = "Error";
                break;
            }
        }
        //Inner loop .....   ///[1...13]  1 => rankName = "Ace", 2 => rankName = "Two", ...
        for(track2 = 1; track2 <= 13; track2++) {
            switch (track2) {
                case 1: {
                    rankName = "Ace";
                    break;
                }
                case 2: {
                    rankName = "Two";
                    break;
                }
                case 3: {
                    rankName = "Three";
                    break;
                }
                case 4: {
                    rankName = "Four";
                    break;
                }
                case 5: {
                    rankName = "Five";
                    break;
                }
                case 6: {
                    rankName = "Six";
                    break;
                }
                case 7: {
                    rankName = "Seven";
                    break;
                }
                case 8: {
                    rankName = "Eight";
                    break;
                }
                case 9: {
                    rankName = "Nine";
                    break;
                }
                case 10: {
                    rankName = "Ten";
                    break;
                }
                case 11: {
                    rankName = "Jack";
                    break;
                }
                case 12: {
                    rankName = "Queen";
                    break;
                }
                case 13: {
                    rankName = "King";
                    break;
                }
                default: {
                    rankName = "Error";
                    break;
                }
            }
            //Print if suit or rank matches, else don't print
            if(matchWord == suitName || matchWord == rankName || matchWord == ".") {
                cout << rankName << " of " << suitName << endl;
                matchFound = true;
            }
            else {
                continue;
            }
        }
    }

    //No match output
    if (!matchFound) {
        cout << " (no matches)" << endl;
    }

    //Finish output with a line
    cout << LINE;
    return 0;
}
