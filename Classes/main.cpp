#include <iostream>    
#include <vector>       
#include <memory>       
#include <algorithm> 
#include <cstring>     
#include "VideoGame.h"  
#include "Music.h"
#include "Movie.h"
using namespace std;

// Function prototypes
void addMedia(vector<unique_ptr<Media>>& database);
void searchMedia(const vector<unique_ptr<Media>>& database);
void deleteMedia(vector<unique_ptr<Media>>& database);
void displayMenu();
void safeGetLine(char* buffer, int size);

int main() {
    vector<unique_ptr<Media>> database;
    char command[MAX_STRING];

    //the main program loop :)
    while (true) {
        displayMenu();
        safeGetLine(command, MAX_STRING);

        //Process user commands
        if (strcmp(command, "ADD") == 0) {
            addMedia(database);
        }
        else if (strcmp(command, "SEARCH") == 0) {
            searchMedia(database);
        }
        else if (strcmp(command, "DELETE") == 0) {
            deleteMedia(database);
        }
        else if (strcmp(command, "QUIT") == 0) {
            break;  //Exit the program
        }
        else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}

//reads user input
void safeGetLine(char* buffer, int size) {
    cin.getline(buffer, size);
    if (cin.fail()) {
        cin.clear();  //cllkear errors
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
}

//Displays the main menu options to the user
void displayMenu() {
    cout << "\nMedia Database Menu:\n"
         << "ADD - Add new media\n"
         << "SEARCH - Search for media\n"
         << "DELETE - Delete media\n"
         << "QUIT - Exit program\n"
         << "Enter command: ";
}

//Adds a new media item to the database
 
void addMedia(vector<unique_ptr<Media>>& database) {
    // Display media type options
    cout << "What type of media would you like to add?\n"
         << "1. Video Game\n"
         << "2. Music\n"
         << "3. Movie\n"
         << "Enter choice (1-3): ";
    
    //Variables 
    char choice[MAX_STRING];
    char title[MAX_STRING];
    char publisher[MAX_STRING];
    char artist[MAX_STRING];
    char director[MAX_STRING];
    char rating[MAX_STRING];
    int year, duration;

    //media type choice
    safeGetLine(choice, MAX_STRING);

    //common fields for all media types
    cout << "Enter title: ";
    safeGetLine(title, MAX_STRING);
    cout << "Enter year: ";
    cin >> year;
    cin.ignore();  // Clear newline from input buffer
    cout << "Enter publisher: ";
    safeGetLine(publisher, MAX_STRING);

    //Handle specific media type input and creation
    if (strcmp(choice, "1") == 0) {
        //Video Game
        cout << "Enter rating: ";
        safeGetLine(rating, MAX_STRING);
        database.push_back(make_unique<VideoGame>(title, year, publisher, rating));
    }
    else if (strcmp(choice, "2") == 0) {
        //Music
        cout << "Enter artist: ";
        safeGetLine(artist, MAX_STRING);
        cout << "Enter duration (in seconds): ";
        cin >> duration;
        cin.ignore();
        database.push_back(make_unique<Music>(title, year, publisher, artist, duration));
    }
    else if (strcmp(choice, "3") == 0) {
        //Movie
        cout << "Enter director: ";
        safeGetLine(director, MAX_STRING);
        cout << "Enter duration (in minutes): ";
        cin >> duration;
        cin.ignore();
        cout << "Enter rating: ";
        safeGetLine(rating, MAX_STRING);
        database.push_back(make_unique<Movie>(title, year, publisher, director, duration, rating));
    }
}


  //Searches for media items in the database
void searchMedia(const vector<unique_ptr<Media>>& database) {
    cout << "Search by:\n"
         << "1. Title\n"
         << "2. Year\n"
         << "Enter choice (1-2): ";
    
    char choice[MAX_STRING];
    safeGetLine(choice, MAX_STRING);

    //Search ttle
    if (strcmp(choice, "1") == 0) {
        char searchTitle[MAX_STRING];
        cout << "Enter title to search for: ";
        safeGetLine(searchTitle, MAX_STRING);

        bool found = false;
        //go through database and display matching items
        for (const auto& media : database) {
            if (strcmp(media->getTitle(), searchTitle) == 0) {
                media->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No matches found.\n";
        }
    }
    //Search by year
    else if (strcmp(choice, "2") == 0) {
        int searchYear;
        cout << "Enter year to search for: ";
        cin >> searchYear;
        cin.ignore();

        bool found = false;
        //Iterate through database and display matching items
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


 //Deletes items from the database
void deleteMedia(vector<unique_ptr<Media>>& database) {
    cout << "Delete by:\n"
         << "1. Title\n"
         << "2. Year\n"
         << "Enter choice (1-2): ";
    
    char choice[MAX_STRING];
    safeGetLine(choice, MAX_STRING);

    //Delete by title
    if (strcmp(choice, "1") == 0) {
        char deleteTitle[MAX_STRING];
        cout << "Enter title to delete: ";
        safeGetLine(deleteTitle, MAX_STRING);

        // Find items to delete using remove_if algorithm
        auto it = remove_if(database.begin(), database.end(),
            [&deleteTitle](const auto& media) {
                return strcmp(media->getTitle(), deleteTitle) == 0;
            });

        // If items were found, confirm deletion
        if (it != database.end()) {
            cout << "Found matching items. Confirm deletion (y/n): ";
            char confirm[MAX_STRING];
            safeGetLine(confirm, MAX_STRING);
            
            if (strcmp(confirm, "y") == 0 || strcmp(confirm, "Y") == 0) {
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
    //Delete by year
    else if (strcmp(choice, "2") == 0) {
        int deleteYear;
        cout << "Enter year to delete: ";
        cin >> deleteYear;
        cin.ignore();

        //find items to delete 
        auto it = remove_if(database.begin(), database.end(),
            [deleteYear](const auto& media) {
                return media->getYear() == deleteYear;
            });

        //If items were found delete it
        if (it != database.end()) {
            cout << "Found it. are you sure you want to delete it? (y/n): ";
            char confirm[MAX_STRING];
            safeGetLine(confirm, MAX_STRING);
            
            if (strcmp(confirm, "y") == 0 || strcmp(confirm, "Y") == 0) {
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
