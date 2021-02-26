// Edward Nieto w0723820
// CISP400 Spring 2021
// Professor Huang

// Purpose  produce a grading program for that calculates the GPA 
// for a set of grades.  It will display the inforamtion.  The Program 
// includes filters for the entries as well as display it in a certain 
// format.

// Member functions are defined in GradeBook.cpp

#include <string> // program uses C++ standard string class
#include <array>

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
   void displayGradeReport();  // display report based on user input
   void displayInputs() const; // display report of entered user input
   double calculateGrade(); // calculates the GPA display report of entered user input
   ~GradeBook(); // removes the object from memory

   // establish private variables
private:
   std::string courseName; // course name for this GradeBook
   std::array<char, 100 > letterGrades; // stores up to 100 grades in the array
   std::array<int, 6 > countGrades;  // stores the number of each letter grade 
                                    // as well as how many error input
   std::size_t letterGradesCount =0; //  Keep a count of number of grades entered

}; // end class GradeBook  
#endif