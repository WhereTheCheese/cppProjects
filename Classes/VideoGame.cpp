#include "VideoGame.h"
#include <iostream>
using namespace std;

VideoGame::VideoGame(const char* title, int year, const char* publisher, const char* rating)
    : Media(title, year, publisher) {
    strncpy(this->rating, rating, MAX_STRING - 1);
    this->rating[MAX_STRING - 1] = '\0';
}

const char* VideoGame::getRating() const { return rating; }

void VideoGame::displayInfo() const {
    cout << "Video Game: " << title << "\n"
         << "Year: " << year << "\n"
         << "Publisher: " << publisher << "\n"
         << "Rating: " << rating << "\n";
}
