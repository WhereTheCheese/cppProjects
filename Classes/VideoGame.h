#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Media.h"

class VideoGame : public Media {
private:
    char rating[10];

public:
    VideoGame();
    virtual ~VideoGame();
    
    void setRating(const char* r);
    const char* getRating() const;
    virtual const char* getType() const override;
};
