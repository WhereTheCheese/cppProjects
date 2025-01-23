#include <iostream>
#include <vector>
#include <cstring>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void addMedia(vector<Media*>& database);
void searchMedia(const vector<Media*>& database);
void deleteMedia(vector<Media*>& database);
void displayMedia(const Media* media);
bool compareStrings(const char* str1, const char* str2);

int main() {
    vector<Media*> database;
    char command[20];

    cout << "Media Database Management System" << endl;
    cout << "Available commands: ADD, SEARCH, DELETE, QUIT" << endl;

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;
        
        //convert to same case 
        for (int i = 0; command[i]; i++) {
            command[i] = toupper(command[i]);
        }

        if (compareStrings(command, "QUIT")) {
            break;
        }
        else if (compareStrings(command, "ADD")) {
            addMedia(database);
        }
        else if (compareStrings(command, "SEARCH")) {
            searchMedia(database);
        }
        else if (compareStrings(command, "DELETE")) {
            deleteMedia(database);
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    //clean up some memory
    for (Media* item : database) {
        delete item;
    }

    return 0;
}

void addMedia(vector<Media*>& database) {
    char type[20];
    cout << "Enter media type (GAME/MUSIC/MOVIE): ";
    cin >> type;

    //make the letters BIG
    for (int i = 0; type[i]; i++) {
        type[i] = toupper(type[i]);
    }

    Media* newMedia = nullptr;
    char buffer[100];
    int numberBuffer;

    if (compareStrings(type, "GAME")) {
        VideoGame* game = new VideoGame();
        
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(buffer, 100);
        game->setTitle(buffer);

        cout << "Enter year: ";
        cin >> numberBuffer;
        game->setYear(numberBuffer);

        cout << "Enter publisher: ";
        cin.ignore();
        cin.getline(buffer, 100);
        game->setPublisher(buffer);

        cout << "Enter rating: ";
        cin.getline(buffer, 10);
        game->setRating(buffer);

        newMedia = game;
    }
    else if (compareStrings(type, "MUSIC")) {
        Music* music = new Music();
        
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(buffer, 100);
        music->setTitle(buffer);

        cout << "Enter artist: ";
        cin.getline(buffer, 100);
        music->setArtist(buffer);

        cout << "Enter year: ";
        cin >> numberBuffer;
        music->setYear(numberBuffer);

        cout << "Enter duration (in seconds): ";
        cin >> numberBuffer;
        music->setDuration(numberBuffer);

        cout << "Enter publisher: ";
        cin.ignore();
        cin.getline(buffer, 100);
        music->setPublisher(buffer);

        newMedia = music;
    }
    else if (compareStrings(type, "MOVIE")) {
        Movie* movie = new Movie();
        
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(buffer, 100);
        movie->setTitle(buffer);

        cout << "Enter director: ";
        cin.getline(buffer, 100);
        movie->setDirector(buffer);

        cout << "Enter year: ";
        cin >> numberBuffer;
        movie->setYear(numberBuffer);

        cout << "Enter duration (in minutes): ";
        cin >> numberBuffer;
        movie->setDuration(numberBuffer);

        cout << "Enter rating: ";
        cin.ignore();
        cin.getline(buffer, 10);
        movie->setRating(buffer);

        newMedia = movie;
    }
    else {
        cout << "Invalid media type!" << endl;
        return;
    }

    database.push_back(newMedia);
    cout << "Media added successfully!" << endl;
}

void searchMedia(const vector<Media*>& database) {
    if (database.empty()) {
        cout << "Database is empty!" << endl;
        return;
    }

    char searchType[20];
    cout << "Search by (TITLE/YEAR): ";
    cin >> searchType;

    //convert to upper case again lol
    for (int i = 0; searchType[i]; i++) {
        searchType[i] = toupper(searchType[i]);
    }

    bool found = false;

    if (compareStrings(searchType, "TITLE")) {
        char searchTitle[100];
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(searchTitle, 100);

        for (const Media* item : database) {
            if (compareStrings(item->getTitle(), searchTitle)) {
                displayMedia(item);
                found = true;
            }
        }
    }
    else if (compareStrings(searchType, "YEAR")) {
        int searchYear;
        cout << "Enter year: ";
        cin >> searchYear;

        for (const Media* item : database) {
            if (item->getYear() == searchYear) {
                displayMedia(item);
                found = true;
            }
        }
    }
    else {
        cout << "Invalid search type!" << endl;
        return;
    }

    if (!found) {
        cout << "No matching items found." << endl;
    }
}

void deleteMedia(vector<Media*>& database) {
    if (database.empty()) {
        cout << "Database is empty!" << endl;
        return;
    }

    char searchTitle[100];
    cout << "Enter title to delete: ";
    cin.ignore();
    cin.getline(searchTitle, 100);

    vector<size_t> matchingIndices;

    //find items that match up
    for (size_t i = 0; i < database.size(); i++) {
        if (compareStrings(database[i]->getTitle(), searchTitle)) {
            displayMedia(database[i]);
            matchingIndices.push_back(i);
        }
    }

    if (matchingIndices.empty()) {
        cout << "No matching items found." << endl;
        return;
    }

    char confirm;
    cout << "Delete these items? (Y/N): ";
    cin >> confirm;

    if (toupper(confirm) == 'Y') {

        for (int i = matchingIndices.size() - 1; i >= 0; i--) {
            delete database[matchingIndices[i]];
            database.erase(database.begin() + matchingIndices[i]);
        }
        cout << "Items deleted successfully!" << endl;
    }
}

void displayMedia(const Media* media) {
    cout << "\n=== " << media->getType() << " ===" << endl;
    cout << "Title: " << media->getTitle() << endl;
    cout << "Year: " << media->getYear() << endl;
    
    if (const VideoGame* game = dynamic_cast<const VideoGame*>(media)) {
        cout << "Publisher: " << game->getPublisher() << endl;
        cout << "Rating: " << game->getRating() << endl;
    }
    else if (const Music* music = dynamic_cast<const Music*>(media)) {
        cout << "Artist: " << music->getArtist() << endl;
        cout << "Duration: " << music->getDuration() << " seconds" << endl;
        cout << "Publisher: " << music->getPublisher() << endl;
    }
    else if (const Movie* movie = dynamic_cast<const Movie*>(media)) {
        cout << "Director: " << movie->getDirector() << endl;
        cout << "Duration: " << movie->getDuration() << " minutes" << endl;
        cout << "Rating: " << movie->getRating() << endl;
    }
}

bool compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2) == 0;
}
