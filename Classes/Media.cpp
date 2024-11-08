#include "Media.h"

Media::Media(string title, int year, string publisher)
    : title(title), year(year), publisher(publisher) {}

string Media::getTitle() const { return title; }
int Media::getYear() const { return year; }
string Media::getPublisher() const { return publisher; }

// VideoGame.cpp - Video game class implementation
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
