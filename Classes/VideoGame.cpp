#include "VideoGame.h"
#include <cstring>

VideoGame::VideoGame() {
    rating[0] = '\0';
}

VideoGame::~VideoGame() {}

void VideoGame::setRating(const char* r) {
    strncpy(rating, r, 9);
    rating[9] = '\0';
}

const char* VideoGame::getRating() const {
    return rating;
}

const char* VideoGame::getType() const {
    return "Video Game";
}
