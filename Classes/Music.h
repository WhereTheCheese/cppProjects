#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"

class Music : public Media {
private:
    string artist;
    int duration; // in seconds

public:
    // Constructor
    Music(string title = "", int year = 0, string publisher = "",
          string artist = "", int duration = 0);
    
    // Getters
    string getArtist() const;
    int getDuration() const;
    
    // Override display method
    void displayInfo() const override;
};
#endif
