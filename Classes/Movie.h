#include "Music.h"
#include <cstring>

Music::Music() {
    artist[0] = '\0';
    duration = 0;
}

Music::~Music() {}

void Music::setArtist(const char* a) {
    strncpy(artist, a, 99);
    artist[99] = '\0';
}

void Music::setDuration(int d) {
    duration = d;
}

const char* Music::getArtist() const {
    return artist;
}

int Music::getDuration() const {
    return duration;
}

const char* Music::getType() const {
    return "Music";
}
