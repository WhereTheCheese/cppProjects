#include "Music.h"
#include <iostream>
using namespace std;

Music::Music(string title, int year, string publisher, 
             string artist, int duration)
    : Media(title, year, publisher), artist(artist), duration(duration) {}

string Music::getArtist() const { return artist; }
int Music::getDuration() const { return duration; }

void Music::displayInfo() const {
    cout << "Music: " << title << "\n"
         << "Artist: " << artist << "\n"
         << "Year: " << year << "\n"
         << "Duration: " << duration / 60 << ":" 
         << duration % 60 << "\n"
         << "Publisher: " << publisher << "\n";
}
