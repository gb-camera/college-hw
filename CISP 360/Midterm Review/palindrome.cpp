#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string inFile;
    cout << "Enter a file name: ";
    cin >> inFile;

    ifstream ifs(inFile);
    if(!ifs.is_open()) {
        cout << "File open failed: " << inFile << endl;
        return 1;
    }
    ofstream ofs("outfile.txt");
    if(!ofs.is_open()) {
        cout << "File open failed: outfile.txt" << endl;
        return 1;
    }

    string s;
    int palCounter = 0;

    while(ifs >> s) {
        bool isPalindrome = true;
        for(int i = 0; i < s.size() / 2 && isPalindrome; i++) {
            if(s[i] != s[s.size() - i - 1]) {
                isPalindrome = false;
            }
        }
        if(isPalindrome) {
            palCounter++;
            ofs << s << endl;
        }
    }

    cout << "Number of palindromes: " << palCounter << endl;
    return 0;
}

