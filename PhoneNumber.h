//fig 10.3  PhoneNumbers.h
// Phonenumber class dedfinition

#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>

class PhoneNumber{
    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&);

    private:
        std::string areaCode; // 3 - digit area code
        std:: string exchange; // 3 - digit exchange
        std:: string line; // 4 - digit line


}; // ends PhoneNumber

#endif// ENDS PHONENUMBER_H
