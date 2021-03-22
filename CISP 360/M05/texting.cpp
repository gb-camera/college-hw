#include <iostream>
#include <string>
using namespace std;

const string BFF = "BFF";
const string IDK = "IDK";
const string JK = "JK";
const string TMI = "TMI";
const string TTYL = "TTYL";

const string BFF_LONG = "best friend forever";
const string IDK_LONG = "I don't know";
const string JK_LONG = "just kidding";
const string TMI_LONG = "too much information";
const string TTYL_LONG = " talk to you later";

int main() 
{
   //Declare a string to hold the sentence
   string input = "AAAAAAAA";

   //Prompt the user input
   cout << "Enter text:" << endl;
   getline(cin, input);
   
   //Declare a variable to hold a search index
   int index = 0;
   
   //Implement a find and replace while loop for each abbreviation (5 total)
   while(input.find(BFF) != string::npos) {
      index = input.find(BFF);
      input.replace(index, 3, BFF_LONG);
   }
   while(input.find(IDK) != string::npos) {
      index = input.find(IDK);
      input.replace(index, 3, IDK_LONG);
   }
   while(input.find(JK) != string::npos) {
      index = input.find(JK);
      input.replace(index, 2, JK_LONG);
   }
   while(input.find(TMI) != string::npos) {
      index = input.find(TMI);
      input.replace(index, 3, TMI_LONG);
   }
   while(input.find(TTYL) != string::npos) {
      index = input.find(TTYL);
      input.replace(index, 4, TTYL_LONG);
   }

   //Use a for loop to iterate through each character of the string and replace any '.' with '!'
   for(int indexD = 0; indexD < input.size(); indexD++) {
      if(input.at(indexD) == '.') {
         input.replace(indexD, 1, "!");
      }
   }
   //Output the modified string
   cout << endl << input << endl;

   return 0;
}