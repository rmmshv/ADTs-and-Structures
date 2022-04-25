// Specification file for the Student class
// Modified by: Rimma Esheva
// IDE: VS Code

#ifndef STUDENT_H
#define STUDENT_H

//using namespace std;  //<==== This statement
// in a header file of a complex project could create
// namespace management problems for the entire project
// (such as name collisions).
// Do not write namespace using statements at the top level in a header file!
#include <string>
using std::string;

class Student
{
private:
    double gpa;
    std::string name;

public:
    // Default and overloaded constructors
    Student() {
        gpa = -1;
        name = "";
    };
    Student(double GPA, std::string NAME) {
        gpa = GPA;
        name = NAME;
    };
    
    // Setters
    void setGpa(double GPA) { gpa = GPA; }
    void setName(std::string NAME) { name = NAME; }
    // Getters
    double getGpa() { return gpa; }
    std::string getName() { return name; }
};


#endif
