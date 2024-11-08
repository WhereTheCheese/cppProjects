#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Media.h"

class VideoGame : public Media {
private:
    string rating;

public:
    // Constructor
    VideoGame(string title = "", int year = 0, string publisher = "", 
             string rating = "");
    
    // Getter for rating
    string getRating() const;
    
    // Override display method
    void displayInfo() const override;
};
#endif
