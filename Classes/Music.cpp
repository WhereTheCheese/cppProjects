#include "Music.h"
#include <iostream>
using namespace std;

Music::Music(const char* title, int year, const char* publisher, 
             const char* artist, int duration)
    : Media(title, year, publisher), duration(duration) {
    strncpy(this->artist, artist, MAX_STRING - 1);
    this->artist[MAX_STRING - 1] = '\0';
}

const char* Music::getArtist() const { return artist; }
int Music::getDuration() const { return duration; }

void Music::displayInfo() const {
    cout << "Music: " << title << "\n"
         << "Artist: " << artist << "\n"
         << "Year: " << year << "\n"
         << "Duration: " << duration / 60 << ":" 
         << duration % 60 << "\n"
         << "Publisher: " << publisher << "\n";
}
