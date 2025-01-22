#include "Media.h"
#include <cstring>

Media::Media() {
    title[0] = '\0';
    publisher[0] = '\0';
    year = 0;
}

Media::~Media() {}

void Media::setTitle(const char* t) {
    strncpy(title, t, 99);
    title[99] = '\0';
}
void Media::setYear(int y) {
    year = y;
}
void Media::setPublisher(const char* p) {
    strncpy(publisher, p, 99);
    publisher[99] = '\0';
}
const char* Media::getTitle() const {
    return title;
}
int Media::getYear() const {
    return year;
}
const char* Media::getPublisher() const {
    return publisher;
}
