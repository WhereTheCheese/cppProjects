#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media {
private:
    char director[100];
    int duration;
    char rating[10];

public:
    Movie();
    virtual ~Movie();
    
    void setDirector(const char* d);
    void setDuration(int d);
    void setRating(const char* r);
    const char* getDirector() const;
    int getDuration() const;
    const char* getRating() const;
    virtual const char* getType() const override;
};
#endif
