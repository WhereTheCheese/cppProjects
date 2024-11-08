#ifndef MOVIE_H
#define MOVIE_H
#include "Media.h"

class Movie : public Media {
private:
    string director;
    int duration; // in minutes
    string rating;

public:
    // Constructor
    Movie(string title = "", int year = 0, string publisher = "",
          string director = "", int duration = 0, string rating = "");
    
    // Getters
    string getDirector() const;
    int getDuration() const;
    string getRating() const;
    
    // Override display method
    void displayInfo() const override;
};
#endif
