#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 4000000;
const string FILE_NAME = "GoogleWords.txt";
string a[MAX_SIZE];

void insertionSort(string a[], int size);
int binarySearch(string a[], string key, int size);
int readDictionary(string a[], string fileName);
void writeDictionary(string a[], int size, string fileName);
int updateDictionary(string a[], int size, string s, string fileName);
void outputMatches(string a[], int size, string s);

int main()
{
    int size = readDictionary(a, FILE_NAME);
    string input;
    cout << "Type one word.  \"q\" to quit." << endl;
    cout << "> ";
    cin >> input;
    while(input != "q")
    {
        outputMatches(a, size, input);
        size = updateDictionary(a, size, input, FILE_NAME);
        cout << "> ";
        cin >> input;
    }
    return 0;
}

///TODO(0)  define binarySearch
int binarySearch(string a[], string key, int size) {
    int mid, low = 0, high = size - 1;
    while (high >= low) {
        mid = (high + low) / 2;
        if(a[mid] < key) {
            low = mid + 1;
        }
        else if(a[mid] > key) {
            high = mid - 1;
        }
        else if (a[mid] == key) {
            return mid;
        }
    }
    return -1;
}
///TODO(1)  define insertionSort
void insertionSort(string a[], int size) {
   int i;
   int j;
   string temp;
   for (i = 1; i < size; ++i) {
      j = i;
      while (j > 0 && a[j] < a[j - 1]) {
         temp = a[j];
         a[j] = a[j - 1];
         a[j - 1] = temp;
         --j;
      }
   }
}
///TODO(2)  define readDictionary
int readDictionary(string a[], string fileName) {
    int sizeCount = 0;
    ifstream ifS(fileName);
    if(!ifS.is_open()) {
        cout << "Error reading dictionary file for input!" << endl;
        return -1;
    }
    while(ifS >> a[sizeCount]) {
        sizeCount++;
    }
    return sizeCount;
}
///TODO(3)  define writeDictionary
void writeDictionary(string a[], int size, string fileName) {
    ofstream ofS(fileName);
    if(!ofS.is_open()) {
        cout << "Error reading dictionary file for input!" << endl;
        return;
    }
    for(int i = 0; i < size; i++) {
        ofS << a[i] << endl;
    }
}

///TODO(4)  define updateDictionary
int updateDictionary(string a[], int size, string s, string fileName) {
    int returned = binarySearch(a, s, size);
    if(returned == -1) {
        a[size] = s;
        size++;
        insertionSort(a, size);
        writeDictionary(a, size, FILE_NAME);
    }
    return size;
}

///TODO(5)  define outputMatches
void outputMatches(string a[], int size, string s) {
    for(int i = 0; i < size; i++) {
        if(a[i].find(s) == 0) {
            cout << a[i] << endl;
        }
    }
}