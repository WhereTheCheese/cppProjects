#ifndef MUSIC_H
#define MUSIC_H
#include "Media.h" 

class Music : public Media {  // Added public inheritance
private:
    char artist[MAX_STRING];
    int duration;

public:
    Music(const char* title = "", int year = 0, const char* publisher = "",
          const char* artist = "", int duration = 0);
    const char* getArtist() const;
    int getDuration() const;
    void displayInfo() const override;
};
#endif
