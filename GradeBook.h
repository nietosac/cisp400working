//  GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

//prevent multiple inclusion of header
#ifndef GRADEBOOK_H
#define GRADEBOOK_h

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void inputGrades(); // input arbitrary number of grades from user
   void displayGradeReport() const;  // display report based on user input
private:
   std::string courseName; // course name for this GradeBook
   unsigned int aCount; // count of A grades
   unsigned int bCount; // count of B grades
   unsigned int cCount; // count of C grades
   unsigned int dCount; // count of D grades
   unsigned int fCount; // count of F grades

   // establish private variables
//private:
   // std::string courseName;         //  stores course name information 
    //DELETE std::
 //   array<char, 100 > letterGrades; // stores up to 100 grades in the array
   // DELETE std::
 //   array<char, 6 > countGrades;  // stores the number of each letter grade 
                                    // as well as how many error input
}; // end class GradeBook  
#endif