#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

class Student {
public:
    //constructor and destructor
    Student();
    ~Student();
    
    //getters
    char* getFirstName();
    char* getLastName();
    int getID();
    float getGPA();
    
    //setters
    void setFirstName(const char* name);
    void setLastName(const char* name);
    void setID(int newID);
    void setGPA(float newGPA);

private:
    char* firstName;
    char* lastName;
    int id;
    float gpa;
};

#endif
