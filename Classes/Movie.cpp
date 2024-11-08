#include "Movie.h"
#include <iostream>
using namespace std;

Movie::Movie(string title, int year, string publisher,
             string director, int duration, string rating)
    : Media(title, year, publisher), director(director), 
      duration(duration), rating(rating) {}

string Movie::getDirector() const { return director; }
int Movie::getDuration() const { return duration; }
string Movie::getRating() const { return rating; }

void Movie::displayInfo() const {
    cout << "Movie: " << title << "\n"
         << "Director: " << director << "\n"
         << "Year: " << year << "\n"
         << "Duration: " << duration << " minutes\n"
         << "Rating: " << rating << "\n"
         << "Publisher: " << publisher << "\n";
}
