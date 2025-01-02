#ifndef MEDIA_H
#define MEDIA_H
#include <cstring>
using namespace std;

const int MAX_STRING = 100;  // Define this in Media.h so all files can access it

class Media {
protected:
    char title[MAX_STRING];
    int year;
    char publisher[MAX_STRING];

public:
    Media(const char* title = "", int year = 0, const char* publisher = "");
    virtual ~Media() = default;
    
    virtual const char* getTitle() const;
    virtual int getYear() const;
    virtual const char* getPublisher() const;
    virtual void displayInfo() const = 0;
};
#endif
