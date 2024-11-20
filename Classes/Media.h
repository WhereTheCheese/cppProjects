#ifndef MEDIA_H
#define MEDIA_H
#include <cstring>
using namespace std;

const int MAX_STRING = 100;  

class Media {
protected:
    char title[MAX_STRING];
    int year;
    char publisher[MAX_STRING];

public:
    //constructor
   Media(const char* title = "", int year = 0, const char* publisher = "");
    
    //Virtual destructor
    virtual ~Media() = default;
    
    // Virtual methods for common fields
    virtual const char* getTitle() const;
    virtual int getYear() const;
    virtual string getPublisher() const;
    
    // Pure virtual method to make this an abstract class
    virtual void displayInfo() const = 0;
}; #endif
