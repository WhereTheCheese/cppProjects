#include "Student.h"
#include <cstring>

Student::Student() {
    //start with emptu strings
    firstName = new char[1];
    firstName[0] = '\0';
    lastName = new char[1];
    lastName[0] = '\0';
    id = 0;
    gpa = 0.0;
}

Student::~Student() {
    //dynamicly allocated memory
    delete[] firstName;
    delete[] lastName;
}

char* Student::getFirstName() {
    return firstName;
}

char* Student::getLastName() {
    return lastName;
}

int Student::getID() {
    return id;
}

float Student::getGPA() {
    return gpa;

void Student::setFirstName(const char* name) {
    //Delete old first name 
    delete[] firstName;
    firstName = new char[strlen(name) + 1];
    strcpy(firstName, name);
}

void Student::setLastName(const char* name) {
    //old last name
    delete[] lastName;
    lastName = new char[strlen(name) + 1];
    strcpy(lastName, name);
}

void Student::setID(int newID) {
    id = newID;
}

void Student::setGPA(float newGPA) {
    gpa = newGPA;
