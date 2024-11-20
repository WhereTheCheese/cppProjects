#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h"

class Music : public Media {
private:
    char artist[MAX_STRING];
    int duration; // in seconds

public:
    //Cconstructor
    Music(const char* title = "", int year = 0, const char* publisher = "",
          const char* artist = "", int duration = 0);
    
    //getters
    const char* getArtist() const;
    int getDuration() const;
    
    //Override display method
    void displayInfo() const override;
};
#endif
