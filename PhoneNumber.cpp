//fig 10.4 PhoneNumber.cpp
// Overloaded  stream insertaion and stream extraction operators
// for class PhoneNumber.

#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

// Overloaded stream insertion operator; cannot be a member function
// if we would like to invoe i with cout << somePhoneNumber;
ostream& operator<<(ostream& output, const PhoneNumber& number) {
    output << "Area code3:" << number.areaCode << "\nExchange1: "
        << number.exchange << "\nLine2: " << number.line << "\n"
        << "(" << number.areaCode << ") " << number.exchange << "-"
        << number.line << "\n";
        return output; // enables cout << a << b << c;
} // ends ostream&

//overloaded stream extractor operatot >>; cannot be a member function 
//if we would like to invoke it with cin >> somePhoneNumber;
istream& operator>>(istream& input, PhoneNumber& number){
    input.ignore(); // skip (
    input >> setw(3) >> number.areaCode; // input area code
    input.ignore(2); //skip ) and space
    input >> setw(3) >> number.exchange; // input exchnage 
    input.ignore(); // skip -
    input >> setw(4) >> number.line; // input line
    return input; //enables cin >> a>> b >> c;
} // ends istream



