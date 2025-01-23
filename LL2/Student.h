#ifndef STUDENT_H
#define STUDENT_H

#include <string> 
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    int id;
    double gpa;

public:
    Student(const string& firstName, const string& lastName, int id, double gpa);

    
    string getFirstName() const;
    string getLastName() const;
    int getID() const;
    double getGPA() const;

    //helps create a new student from the student name
    static Student* createFromFirstName(const char* firstName);
};

#endif



