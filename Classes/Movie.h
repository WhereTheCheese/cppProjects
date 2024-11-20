#ifndef MOVIE_H
#define MOVIE_H
#include "Media.h"

class Movie : public Media {
private:
     char director[MAX_STRING];
    int duration;
    char rating[MAX_STRING];

public:
    //Constructor
    Movie(const char* title = "", int year = 0, const char* publisher = "",
          const char* director = "", int duration = 0, const char* rating = "");
    
    //getters
    const char* getDirector() const;
    int getDuration() const;
    const char* getRating() const;
    
    //Override display method
    void displayInfo() const override;
};
#endif
