
#include "Movie.h"
#include <cstring>

Movie::Movie() {
    director[0] = '\0';
    duration = 0;
    rating[0] = '\0';
}

Movie::~Movie() {}

void Movie::setDirector(const char* d) {
    strncpy(director, d, 99);
    director[99] = '\0';
}

void Movie::setDuration(int d) {
    duration = d;
}

void Movie::setRating(const char* r) {
    strncpy(rating, r, 9);
    rating[9] = '\0';
}

const char* Movie::getDirector() const {
    return director;
}

int Movie::getDuration() const {
    return duration;
}

const char* Movie::getRating() const {
    return rating;
}

const char* Movie::getType() const {
    return "Movie";
}
