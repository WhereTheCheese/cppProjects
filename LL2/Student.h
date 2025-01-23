// Student.h
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

#include <string>

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
};

#endif // STUDENT_H

