#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string inFile;
    cout << "Enter a file name: ";  /// words_alpha.txt
    cin >> inFile;

    ifstream ifs(inFile);

    if(!ifs)
    {
        cout << "File open failed." << endl;
        return 1;
    }

    ofstream ofs("out.txt");

    string s;
    int numPalindromes = 0;

    while(ifs >> s)
    {
        bool isPalindrome = true;
        for(size_t i = 0; i < s.size() / 2 && isPalindrome; i++)
        {
            if(s[i] != s[s.size() - i - 1])
                isPalindrome = false;
        }
        if(isPalindrome)
        {
            numPalindromes++;
            ofs << s << endl;
        }
    }

    cout << "Number of palindromes: " << numPalindromes << endl;

    return 0;
}
