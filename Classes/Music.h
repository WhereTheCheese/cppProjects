#ifndef MUSIC_H
#define MUSIC_H

#include "Media.h"

class Music : public Media {
private:
    char artist[100];
    int duration; // in seconds

public:
    Music();
    virtual ~Music();
    
    void setArtist(const char* a);
    void setDuration(int d);
    const char* getArtist() const;
    int getDuration() const;
    virtual const char* getType() const override;
};
#endif
