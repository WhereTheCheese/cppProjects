#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie(const char* title, int year, const char* publisher,
             const char* director, int duration, const char* rating)
    : Media(title, year, publisher), duration(duration) {
    strncpy(this->director, director, MAX_STRING - 1);
    this->director[MAX_STRING - 1] = '\0';
    strncpy(this->rating, rating, MAX_STRING - 1);
    this->rating[MAX_STRING - 1] = '\0';
}

const char* Movie::getDirector() const { return director; }
int Movie::getDuration() const { return duration; }
const char* Movie::getRating() const { return rating; }

void Movie::displayInfo() const {
    cout << "Movie: " << title << "\n"
         << "Director: " << director << "\n"
         << "Year: " << year << "\n"
         << "Duration: " << duration << " minutes\n"
         << "Rating: " << rating << "\n"
         << "Publisher: " << publisher << "\n";
}
