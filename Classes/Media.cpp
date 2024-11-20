#include "Media.h"
#include <cstring>

Media::Media(const char* title, int year, const char* publisher) {
    strncpy(this->title, title, MAX_STRING - 1);
    this->title[MAX_STRING - 1] = '\0';
    this->year = year;
    strncpy(this->publisher, publisher, MAX_STRING - 1);
    this->publisher[MAX_STRING - 1] = '\0';
}

const char* Media::getTitle() const { return title; }
int Media::getYear() const { return year; }
const char* Media::getPublisher() const { return publisher; }

