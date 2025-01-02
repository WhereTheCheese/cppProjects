#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Media.h"

class VideoGame : public Media {  
private:
    char rating[MAX_STRING];

public:
    VideoGame(const char* title = "", int year = 0, const char* publisher = "", 
             const char* rating = "");
    const char* getRating() const;
    void displayInfo() const override;
};
#endif
