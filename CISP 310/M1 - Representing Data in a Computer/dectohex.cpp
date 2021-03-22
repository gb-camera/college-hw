//Michael Dinh - CISP 310 - Assignment #1
//Binary to Hexadecimal Converter

#include <iostream>
#include <string>
using namespace std;

bool binCheck(string binVal){
    //Check each value and see if it is either 0 or 1
    for(int i = 0; i < binVal.length(); i++){
        //If not, the value isn't binary
        if(binVal.at(i) != '0' && binVal.at(i) != '1'){
            return false;
        }
    }
    return true;
}

int binToDec(unsigned long long int binVal){
    //Initialize our values
    int dec = 0;
    int base = 1; //Starting base for binary is 2^0 = 1
    while(binVal){
        //Get digit corresponding to current base
        int lastDigit = binVal % 10;
        //Multiply obtained digit by the base and add it to the decimal value
        dec += lastDigit * base;
        //Increase the base for the next value
        base = base * 2;
        //Remove previous value from the operator
        binVal = binVal / 10;
    }
    return dec;
}

string decToHex(int decVal){
    //Initialize our values
    string hexVal = "";
    int temp = 0;
    //Define an array of all possible hex values
    string hex[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    while(decVal){
        //Pull remainer from decimal value to convert
        temp = decVal % 16;
        //Convert that remainder to a hexadecimal value using the array and add to the front of the string
        hexVal.insert(0, hex[temp]);
        //Divide the operating number by 16 and start the process again
        decVal = decVal/16;
    }
    return hexVal;
}

int main(){
    //Initialize the values we need
    bool binState = false;
    unsigned long long int binVal = 0; //For REALLY big binary values
    int decVal = 0;
    string hexVal = "";
    //Have user input a binary value
    cout << "Enter a binary value: ";
    cin >> binVal;
    //Error check
    binState = binCheck(to_string(binVal));
    while(!binState){
        cout << "The value you entered is not binary, enter a binary value: ";
        cin >> binVal;
        binState = binCheck(to_string(binVal));
    }
    //Perform conversions
    decVal = binToDec(binVal);
    hexVal = decToHex(decVal);
    //Output result of conversion
    cout << "The corresponding hexadecimal value for " << binVal << " is " << hexVal << endl;
    //Program end
    system("PAUSE");
    return 0;
}