#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"
using namespace std;

// Function prototypes
void addMedia(vector<unique_ptr<Media>>& database);
void searchMedia(const vector<unique_ptr<Media>>& database);
void deleteMedia(vector<unique_ptr<Media>>& database);
void displayMenu();

int main() {
    vector<unique_ptr<Media>> database;
    string command;

    while (true) {
        displayMenu();
        getline(cin, command);

        if (command == "ADD") {
            addMedia(database);
        }
        else if (command == "SEARCH") {
            searchMedia(database);
        }
        else if (command == "DELETE") {
            deleteMedia(database);
        }
        else if (command == "QUIT") {
            break;
        }
        else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
    cout << "\nMedia Database Menu:\n"
         << "ADD - Add new media\n"
         << "SEARCH - Search for media\n"
         << "DELETE - Delete media\n"
         << "QUIT - Exit program\n"
         << "Enter command: ";
}

void addMedia(vector<unique_ptr<Media>>& database) {
    cout << "What type of media would you like to add?\n"
         << "1. Video Game\n"
         << "2. Music\n"
         << "3. Movie\n"
         << "Enter choice (1-3): ";
    
    string choice;
    getline(cin, choice);

    string title, publisher, artist, director, rating;
    int year, duration;

    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();
    cout << "Enter publisher: ";
    getline(cin, publisher);

    if (choice == "1") {
        cout << "Enter rating: ";
        getline(cin, rating);
        database.push_back(make_unique<VideoGame>(title, year, publisher, rating));
    }
    else if (choice == "2") {
        cout << "Enter artist: ";
        getline(cin, artist);
        cout << "Enter duration (in seconds): ";
        cin >> duration;
        database.push_back(make_unique<Music>(title, year, publisher, artist, duration));
    }
    else if (choice == "3") {
        cout << "Enter director: ";
        getline(cin, director);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        cin.ignore();
        cout << "Enter rating: ";
        getline(cin, rating);
        database.push_back(make_unique<Movie>(title, year, publisher, director, duration, rating));
    }
}

void searchMedia(const vector<unique_ptr<Media>>& database) {
    cout << "Search by:\n"
         << "1. Title\n"
         << "2. Year\n"
         << "Enter choice (1-2): ";
    
    string choice;
    getline(cin, choice);

    if (choice == "1") {
        string searchTitle;
        cout << "Enter title to search for: ";
        getline(cin, searchTitle);

        bool found = false;
        for (const auto& media : database) {
            if (media->getTitle() == searchTitle) {
                media->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No matches found.\n";
        }
    }
    else if (choice == "2") {
        int searchYear;
        cout << "Enter year to search for: ";
        cin >> searchYear;

        bool found = false;
        for (const auto& media : database) {
            if (media->getYear() == searchYear) {
                media->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No matches found.\n";
        }
    }
}

void deleteMedia(vector<unique_ptr<Media>>& database) {
    cout << "Delete by:\n"
         << "1. Title\n"
         << "2. Year\n"
         << "Enter choice (1-2): ";
    
    string choice;
    getline(cin, choice);

    if (choice == "1") {
        string deleteTitle;
        cout << "Enter title to delete: ";
        getline(cin, deleteTitle);

        auto it = remove_if(database.begin(), database.end(),
            [&deleteTitle](const auto& media) {
                return media->getTitle() == deleteTitle;
            });

        if (it != database.end()) {
            cout << "Found matching items. Confirm deletion (y/n): ";
            string confirm;
            getline(cin, confirm);
            
            if (confirm == "y" || confirm == "Y") {
                database.erase(it, database.end());
                cout << "Items deleted.\n";
            }
            else {
                cout << "Deletion cancelled.\n";
            }
        }
        else {
            cout << "No matches found.\n";
        }
    }
    else if (choice == "2") {
        int deleteYear;
        cout << "Enter year to delete: ";
        cin >> deleteYear;
        cin.ignore();

        auto it = remove_if(database.begin(), database.end(),
            [deleteYear](const auto& media) {
                return media->getYear() == deleteYear;
            });

        if (it != database.end()) {
            cout << "Found matching items. Confirm deletion (y/n): ";
            string confirm;
            getline(cin, confirm);
            
            if (confirm == "y" || confirm == "Y") {
                database.erase(it, database.end());
                cout << "Items deleted.\n";
            }
            else {
                cout << "Deletion cancelled.\n";
            }
        }
        else {
            cout << "No matches found.\n";
        }
    }
}
