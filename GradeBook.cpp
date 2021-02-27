// Edward Nieto w0723820
// CISP400 Spring 2021
// Professor Huang

// Purpose  produce a grading program for that calculates the GPA 
// for a set of grades.  It will display the inforamtion.  The Program 
// includes filters for  the entries as well as display it in a certain 
// format.  This is the AD assignement, thus the students character array is added 
// as as additional outputs are necessary.

#include <array>    // used for holding the courseGrades, countGrades
#include <string>   // used for courseName 
#include <iostream> // May need for input and output
#include <iomanip>  // may need for stream manipulation
#include <cstring>  // used for centering calculation of cstring

#include "GradeBook.h" //include definition of class GradeBook

using namespace std;

//constructor Gradebook
GradeBook::GradeBook(string name)
// initializes class members  instead of function initializeData
:   letterGrades{}, 
    studentName{},
    studentNameChar{},
    studentNameCount{},
    countGrades{},
    letterGradesCount{} 
    // note no comma at end of initialization

// execution of the constructor bstudentNameCountody
{
    cout << "The GradeBook Constructor is called" << endl;  //as required by assigment

    setCourseName(name); // take parameter name and using fuction setCourseName to set Private variable
    displayMessage();
    cout << "The Grade Book, "<< getCourseName() << ", contains" << endl << endl;
    displayGradeReport();

    cout <<"*****The end of Grade Book Constructor.*****" << endl << endl;
}  //ends constructor

//function setCourseName
void GradeBook::setCourseName(string name){
    // only allow 30 or less characters in coursename
    if(name.size() <= 30){
        courseName = name;
    } 
    else{
        courseName = name.substr(0,30); // Truncate at 30 characters
        cerr << "\tName: \"" << name << "\" \n\texceeds maximum length (30).\n\n"
        << "\tLimiting courseName to first 30 characters.\n" << endl;
    }//ends if... else

}//ends setCourseName

//function getCourseName
string GradeBook::getCourseName() const{
        return courseName;
    }//ends getCourseName


//function initializeData // not needed as used intializer in constructor


//function displayMessage
void GradeBook::displayMessage() const{
        //this statement calls getCourseName to get the 
        //name of the course this GradeBook represents
        cout << "\tWelcome to the grade book for \n\t" << getCourseName() 
        << "!\n" << endl;

    }// ends displayMessage

//function inputData
// input arbitrary number of grades from user; updates grade counter
void GradeBook::inputData(){

    char grade; //  grade variable to be entered by user
      cout << "\tEnter the letter grades," << endl // prompt to user
         << "\t-->     Or Enter the EOF character to end input.\n" 
          << "\tUse Ctl + D, or Ctl + Z" << endl; 



//loop until user enters end of file key sequence
    while ((grade=cin.get()) !=EOF){  
                    
        if(grade != '\n'){                  // Need to check if Enter key is not capture under the default
         
    //use switch to count the grade entered
        switch (grade)                      // switch command  in a while loop
        {
        case 'A':                           //grade was uppercase A
        case 'a':                           //grade was lowercase a
        letterGrades[letterGradesCount] = 'A'; // places "A" for 'a' and 'A' into the array that keeps all entries of
        countGrades[0] += 1;                   // increments counter of entries of A's
        break;//exit switch
        
        case 'B':                               //grade was uppercase B
        case 'b':                               //grade was lowercase b
        letterGrades[letterGradesCount] = 'B';  // places "B" for 'b' and 'B' into the array that keeps all entries
        countGrades[1] += 1;                    // increments counter of entries of B's
        break;//exit switch

        case 'C':                               //grade was uppercase C
        case 'c':                               //grade was lowercase c
        letterGrades[letterGradesCount] = 'C';  // places "C" for 'c' and 'C' into the array that keeps all entries
        countGrades[2] += 1;                    // increments counter of entries of C's
        break;//exit switch

        case 'D':                               //grade was uppercase D
        case 'd':                               //grade was lowercase d
        letterGrades[letterGradesCount] = 'D';  // places "D" for 'd' and 'D' into the array that keeps all entries
        countGrades[3] += 1;                    // increments counter of entries of D's
            break; //exit switch

        case 'F':                               //grade was uppercase F
        case 'f':                               //grade was lowercase f
        letterGrades[letterGradesCount] = 'F';  // places "F" for 'f' and 'F' into the array that keeps all entries
        countGrades[4] += 1;                    // increments counter of entries of F's
            break;//exit switch

        default:                                // catch all other characters
        cout << "XXXX An incorrect letter grade entered. XXXX"
        << "\n\"" << grade << "\"" << " is not a a proper letter grade." << endl;
            //letterGrades[letterGradesCount] = grade;  // places grade into the array that keeps all entries
            //countGrades[5] += 1;                   // increments counter of entries of other entered values
            break; // this is not necessary but keep to be consistent with assignment
        }//end switch statment 



        } // Ends the if then for the "\n" key

// Check if grade was valid (A-F)
        if (letterGrades[letterGradesCount] == 'A' ||
        letterGrades[letterGradesCount] == 'B' ||
        letterGrades[letterGradesCount] == 'C' ||
        letterGrades[letterGradesCount] == 'D' ||
        letterGrades[letterGradesCount] == 'F'         ){
        
        // call inputStudentName() after a proper grade is entered
          
              inputStudentName(letterGradesCount); // Call method 
                studentNameCount +=1;
                letterGradesCount += 1;             // increment after successful student entered 
        } //ends the valid check

    cout << "\tEnter the letter grades," << endl // prompt to user
         << "\t-->     Or Enter the EOF character to end input.\n" 
          << "\tUse Ctl + D, or Ctl + Z" << endl; 
           
    }//end while loop
    if( grade ==EOF && letterGradesCount ==0){
        cout << setw(80) <<"There is no data entered.\n\n" << endl;
    }
}//ends inputData

//function inputStudentName
void GradeBook::inputStudentName(int StudentIndex){
        std::string studentNameT; // local varibale of student name
       
        cout << "Enter a student name."<< endl; //prompt the user for a student name 
        cin.ignore();            // To make the cin to cooperate perahps I should just switch to getline for all entries
        cin.getline(studentNameChar[StudentIndex], 20);
        //studentName[StudentIndex] = studentNameChar;
        cout << "Finished a student name."<< endl;
}//ends inputStudentName


//function displayAllStudentsandGrades
void GradeBook::displayAllStudentsandGrades(){
    cout << "The data entered is listed at the following:" << endl;                         // first header line
    cout << "Index" <<setw(15) <<"Student Name" <<setw(12) << "Grade" 
        << setw(10) << "Index" <<setw(15) <<"Student Name" <<setw(12) << "Grade" << endl;   // Second header line

   // cout << (unsigned)strlen(studentNameChar[0]) << endl;

        for (size_t j{0}; j < studentNameCount-1; j +=2){
            
            int bufferV = ((unsigned)(strlen(studentNameChar[j])/2));
            int bufferV2 = ((unsigned)(strlen(studentNameChar[j+1])/2));

            cout << setw(3) << j << setw((13 + bufferV)) << studentNameChar[j] << setw(15 -bufferV) << letterGrades[j] 
                 << setw(10) << j+1 << setw((13 + bufferV2)) << studentNameChar[j+1] << setw(10 -bufferV2) << letterGrades[j+1] << endl;

                } // end for
// When the studentNameCount is odd number need to add one more
if (studentNameCount != 2*(studentNameCount/2)){  // when not even then 
            int bufferV = ((unsigned)(strlen(studentNameChar[studentNameCount-1])/2));

            cout << setw(3) << studentNameCount-1 << setw((15 - bufferV)) 
                << studentNameChar[studentNameCount-1] << setw(10) << letterGrades[studentNameCount-1] << endl;

}

cout << endl;                                           // To match intended output   
} // ends displayAllStudentsandGrades

//function displayGradeReport
//display a report based ont he grades entered by user
void GradeBook::displayGradeReport()  {
//ouput summary of results

    cout << "The total number of data entered is " << letterGradesCount << endl;
    cout << "The total number of students received graded is " << letterGradesCount - countGrades[5]<< endl;
    cout << "Number of students who received each letter grade:" << endl;
        array<string, 6> gradeLetters {"A", "B","C","D","F", "Error"};  // Local array of Grade Letters

            for(size_t i{0}; i<6; ++i){                                 // with Grade Letters able to do with loop
                cout << gradeLetters[i] << ": "<< setw(i==5?6:10) << countGrades[i]<< endl; //Used Ternary function to achieve alignment
            }
            // GPA calculation and display
           double classAverage = GradeBook::calculateGrade();
            
            cout << "\nThe class average is: " << fixed <<setprecision(1) << classAverage << endl<< endl;
}//ends displayGradeReport



//function displayInputs
//display a report based on the grades entered by user
void GradeBook::displayInputs() const {
//ouput summary of results
   cout << "\n\nThe data entered is listed at the following: " << endl; 
    
    for (size_t i{0}; i <(letterGradesCount/4); ++i){       // First of two loops - The number of lines minus 1 is determined dynamically
        for (size_t j{0}; j < 4; ++j){                      //the 4 moves the cursor to next line after 4 entries
            int elementNumber = j+(4*i);                    // Calculates the element number based on the loops values
            cout << "[" << elementNumber << "]" << "-> " << letterGrades[elementNumber] << "    ";  // outputs the element number and its value
        } //ends for j

       cout << endl;                                        //next line

    }// ends for i

// The last line is any remaining elements of the array.  Determine by the difference of
// letterGradesCount - 4*(letterGradesCount/4)
    int fullLineCount = letterGradesCount/4;
    int lastLineCount = (letterGradesCount - (4 * fullLineCount ));

    if (lastLineCount != 0){                                    // check to be certain their is a reminaing elments
            for (size_t i{0}; i < lastLineCount; ++i){          //loop through remianing elments
                int elementNumber = (i + (4 * fullLineCount )); // claculates the element numbers based on the line and remaining element
                    cout << "[" << elementNumber << "]"  << "-> " << letterGrades[elementNumber] << "    "; // outputs the element number and its value
            }
        }
    cout << endl << endl;
}//ends displayInputs

//function calculateGrade
// This calculates the GPA (Grade Point Average) and return the value
double GradeBook::calculateGrade(){
        double weightedSum = 0.0;                               //local variable and intialized
        double GPA = 0.0;                                       //local variable and intialized
        array <double, 5> letterWeights{4.0,3.0,2.0,1.0,0.0};   //local variable and intialized
        int sumGrades = 0;                                      //local variable and intialized
        
        for(size_t i{0}; i < 5; ++i){                           //loop through all count of grades ( array Countgrades)
            weightedSum = weightedSum +letterWeights[i]*countGrades[i]; // running sum is added for Grade Count  times its weight
            sumGrades = sumGrades + countGrades[i];             // running sum of total count of grades
        }
           
            if (sumGrades != 0){                                // check if total sum is 0 so not to divide by 0
                GPA = weightedSum/(double)sumGrades;            // Calculate GPA based on the two running sums
            }
            else{
                GPA = 0.0;                                      // Set GPA to 0.0 as no grades entered
            }
    
    return  GPA;

}
//destructor Gradebook
GradeBook::~GradeBook(){
    cout << "Destructor is called" << endl;
}// ends destructor


