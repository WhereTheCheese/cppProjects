
#include "VideoGame.h"
#include <iostream>
using namespace std;

VideoGame::VideoGame(string title, int year, string publisher, string rating)
    : Media(title, year, publisher), rating(rating) {}

string VideoGame::getRating() const { return rating; }

void VideoGame::displayInfo() const {
    cout << "Video Game: " << title << "\n"
         << "Year: " << year << "\n"
         << "Publisher: " << publisher << "\n"
         << "Rating: " << rating << "\n";
}
