#ifndef MEDIA_H
#define MEDIA_H
#include <string>
using namespace std;

class Media {
protected:
    string title;
    int year;
    string publisher;

public:
    // Constructor
    Media(string title = "", int year = 0, string publisher = "");
    
    // Virtual destructor
    virtual ~Media() = default;
    
    // Virtual methods for common fields
    virtual string getTitle() const;
    virtual int getYear() const;
    virtual string getPublisher() const;
    
    // Pure virtual method to make this an abstract class
    virtual void displayInfo() const = 0;
}; #endif
