// Edward Nieto w0723820
// CISP400 Spring 2021
// Professor Huang

// Purpose  produce a grading program for that calculates the GPA 
// for a set of grades.  It will display the inforamtion.  The Program 
// includes filters for the entries as well as display it in a certain 
// format.

#include "GradeBook.cpp"

int main()
{
   // create GradeBook object myGradeBook and 
   // pass course name to constructor
   GradeBook myGradeBook( "CISP400 Object Oriented Programming with C++" );

   myGradeBook.displayMessage(); // display welcome message
   myGradeBook.inputGrades(); // read grades from user
   myGradeBook.displayInputs(); // display inputted information
   myGradeBook.displayGradeReport(); // display report based on grades
   myGradeBook.~GradeBook(); // call destructor
	myGradeBook.displayMessage(); //try to display the destroyed object information
   system("PAUSE");
   return 0; // indicate successful termination
} // end main 
