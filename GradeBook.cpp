// Edward Nieto w0723820
// CISP400 Spring 2021
// Professor Huang

// Purpose  produce a grading program for that calculates the GPA 
// for a set of grades.  It will display the inforamtion.  The Program 
// includes filters for the entries as well as display it in a certain 
// format.
// Gradbook class 

#include <array>    // used for holding the courseGrades, countGrades
#include <string>   // used for courseName 
#include <iostream> // May need for input and output
#include <iomanip>  // may need for stream manipulation

//#include "GradeBook.h" //include definition of class GradeBook

using namespace std;

class GradeBook{
private:
    std::string courseName; // course name for this GradeBook
    std::array<char, 100 > letterGrades; // stores up to 100 grades in the array
    std::array<int, 6 > countGrades;  // stores the number of each letter grade 
                                 // as well as how many error input
    std::size_t letterGradesCount =0; //  Keep a count of number of grades entered

//establish public functions
public:
//constructor Gradebook
GradeBook(string name)
// initializes class members 
:   letterGrades{},
    countGrades{},
    letterGradesCount{} 
    // note no comma at end of initialization

// execution of the constructor body
{
    cout << "The GradeBook Constructor is called" << endl;  //as required by assigment

    setCourseName(name); // take parameter name and using fuction setCourseName to set Private variable

    displayMessage();
    cout << "The Grade Book, "<< getCourseName() << ", contains" << endl << endl;

    displayGradeReport();

    cout <<"*****The end of Grade Book Constructor.*****" << endl << endl;
}  //ends constructor

//function setCourseName
void setCourseName(string name){
    // only allow 25 or less characters in coursename
    if(name.size() <= 25){
        courseName = name;
    } 
    else{
        courseName = name.substr(0,30); // Truncate at 30 characters
        cerr << "\tName: \"" << name << "\" \n\texceeds maximum length (30).\n\n"
        << "\tLimiting courseName to first 30 characters.\n" << endl;
    }//ends if... else

}//ends setCourseName

//function getCourseName
string getCourseName() const{
        return courseName;
    }//ends getCourseName


//function initializeData


//function displayMessage
void displayMessage() const{
        //this statement calls getCourseName to get the 
        //name of the course this GradeBook represents
        cout << "\tWelcome to the grade book for \n\t" << getCourseName() 
        << "!\n" << endl;

    }// ends displayMessage

//function inputGrades
    // input arbitray number of grades from user; update grade counter
void inputGrades(){

    char grade; //  grade variable to be entered by user

    cout << "\tEnter the letter grades," << endl // prompt to user
         << "\t-->     Or Enter the EOF character to end input.\n" 
          << "\tUse Ctl + D, or Ctl + Z" << endl; 

//loop until user enters end of file key sequence
    while ((grade =cin.get()) !=EOF){
        
        
        if(grade != '\n'){                  // Need to check if Enter key is not capture under the default
         //DELETE   letterGrades[letterGradesCount] = grade;
         //DELETE   letterGradesCount += 1;
        
       //DELETE  addCharToMaster(grade); // every entry should entered to master list regardless of value

    //use switch to count the grade entered
        switch (grade) // switch natedt in a while loop
        {
        case 'A': //grade was uppercase A
        case 'a': //grade was lowercase a
  //DELETE  cout << "A"<< endl;        //DELETE add to counter of countGrades
         letterGrades[letterGradesCount] = 'A';        
        countGrades[0] += 1;
            break;//exit switch
        
        case 'B': //grade was uppercase B
        case 'b': //grade was lowercase b
    //DELETE cout << "B"<< endl;        //DELETE add to counter of countGrades
           letterGrades[letterGradesCount] = 'B';  
           countGrades[1] += 1;
            break;//exit switch

        case 'C': //grade was uppercase C
        case 'c': //grade was lowercase c
    //DELETE cout << "C"<< endl;        //DELETE add to counter of countGrades
         letterGrades[letterGradesCount] = 'C';  
         countGrades[2] += 1;
             break;//exit switch

        case 'D': //grade was uppercase D
        case 'd': //grade was lowercase d
    //DELETE cout << "D"<< endl;        //DELETE add to counter of countGrades
     letterGrades[letterGradesCount] = 'D';  
     countGrades[3] += 1;
            break; //exit switch

        case 'F': //grade was uppercase F
        case 'f': //grade was lowercase f
    //DELETE cout << "F"<< endl;        //DELETE add to counter of countGrades
     letterGrades[letterGradesCount] = 'F';  
     countGrades[4] += 1;
            break;//exit switch


        default:// catch all other characters
        cout << "XXXX An incorrect letter grade entered. XXXX"
        << "\"" << grade << "\"" << " is not a a proper letter grade." << endl;
            letterGrades[letterGradesCount] = grade;  
            countGrades[5] += 1;
            break; // this is not necessary but keep to be consistent with assignment
        }//end switch statment 
        letterGradesCount += 1;
        } // Ends the if then for the "\n" key
    }//end while loop
}//ends inputGrades



//function displayGradeReport
//display a report based ont he grades entered by user
void displayGradeReport()  {
//ouput ummary of results

    cout << "The total number of data entered is " << letterGradesCount << endl;
    cout << "The total number of students received graded is " << letterGradesCount - countGrades[5]<< endl;
    cout << "Number of students who received each letter grade:" << endl;
        array<string, 6> gradeLetters {"A", "B","C","D","F", "Error"};// Local array of Grade Letters

            for(size_t i{0}; i<6; ++i){ // with Grade Letters able to do with loop
                cout << gradeLetters[i] << ": " << setw(i==5?6:10)<< countGrades [i]<< endl; //Used Ternary function to achieve alignment
            }
            // GPA calculation and display
           double classAverage = calculateGrade();
            
            cout << "\nThe class average is: " << fixed <<setprecision(1) << classAverage << endl<< endl;
}//ends displayGradeReport



//function displayInputs
//display a report based ont he grades entered by user
void displayInputs() const {
//ouput summary of results

//DELETE    cout << "Reached the displayInputs()" << endl;
   cout << "\n\nThe data entered is listed at the following: " << endl;
    
    for (size_t i{0}; i <(letterGradesCount/4); ++i){
        for (size_t j{0}; j < 4; ++j){
            int elementNumber = j+(4*i);
            cout << "[" << elementNumber << "]" << "-> " << letterGrades[elementNumber] << "    ";  
        } //ends for j

       cout << endl; ///next line

    }// ends for i

// The last line is any remaining count between the difference of
// letterGradesCount - 4*(letterGradesCount/4)
    int fullLineCount = letterGradesCount/4;
    int lastLineCount = (letterGradesCount - (4 * fullLineCount ));

    if (lastLineCount != 0){
            for (size_t i{0}; i < lastLineCount; ++i){
                int elementNumber = (i + (4 * fullLineCount )); 
                    cout << "[" << elementNumber << "]"  << "-> " << letterGrades[elementNumber] << "    ";
            }
        }
    cout << endl << endl;
}//ends displayInputs

//function addCharToMaster
// add individual entry to master list
void addCharToMaster(char grade){
//check on added characters already in array
    if(letterGradesCount < 99 ) {
        if(grade != '\n'){
            letterGrades[letterGradesCount +1] = grade;
            letterGradesCount += 1;
        }
    }
    else{
        cout << "The list is already filled, no more grades can be added. " << endl;
    }
//DELETE    letterGradesCount += 1;
}//ends addCharToMaster

//function calculateGrade
// This calculates the GPA (Grade Point Average) and return the value
double calculateGrade(){
        double weightedSum = 0.0;
        double GPA = 0.0;
        array <double, 5> letterWeights{4.0,3.0,2.0,1.0,0.0};
        int sumGrades = 0;
        
        for(size_t i{0}; i < 5; ++i){
            weightedSum = weightedSum +letterWeights[i]*countGrades[i];
            sumGrades = sumGrades + countGrades[i];
        }
           
            if (sumGrades != 0){        
                GPA = weightedSum/(double)sumGrades;
            }
            else{
                GPA = 0.0;
            }
    
    return  GPA;

}
//destructor Gradebook
~GradeBook(){
    cout << "Destructor is called" << endl;
}// ends destructor


};//ends Gradebook class