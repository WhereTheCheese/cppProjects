#ifndef MEDIA_H
#define MEDIA_H

class Media {
protected:
    char title[100];
    int year;
    char publisher[100];

public:
    Media();
    virtual ~Media();
    
    virtual void setTitle(const char* t);
    virtual void setYear(int y);
    virtual void setPublisher(const char* p);
    
    virtual const char* getTitle() const;
    virtual int getYear() const;
    virtual const char* getPublisher() const;
    
    virtual const char* getType() const = 0;
};
