//Fig 10.5 fig10_05.cpp
// demonstrating class PhoneNumber's overlaoded stream insertion 
// and stream extraction operators.

#include <iostream>
#include "PhoneNumber.cpp"
using namespace std;

int main() {
    PhoneNumber phone; // creat object phone
    cout<< "Enter phone mber in the form (555) 555-5555:" << endl;

    //cin>> phone invokes operator>> by implicitly issuing
    // the non-member function call operator >> (cin, phone)
    cin >> phone;

    //cout << phone invokes operator << by implicitly issuing
    // the non-member function call operator<<(cout, phone)
    cout << phone << endl;
}//ends main