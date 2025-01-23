#include "Student.h"
using namespace std;

Student::Student(const string& firstName, const string& lastName, int id, double gpa)
    : firstName(firstName), lastName(lastName), id(id), gpa(gpa) {}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

int Student::getID() const {
    return id;
}

double Student::getGPA() const {
    return gpa;
}

//creates a new student with the first name adn then chagne the other info later. 
Student* Student::createFromFirstName(const char* firstName) {
    return new Student(firstName, "Unknown", -1, 0.0); // i put in values that will change later
}




