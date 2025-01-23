#include "Student.h"
using namespace std;

Student::Student(const std::string& firstName, const std::string& lastName, int id, double gpa)
     firstName(firstName), lastName(lastName), id(id), gpa(gpa) {}

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
