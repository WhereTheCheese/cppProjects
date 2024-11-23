#include <iostream>
#include <vector>
#include "Room.h"
using namespace std;

class Game {
private:
    vector<Room*> rooms;  
    Room* currentRoom;    //where you curretnly are in the game, liek the room
    bool gameOver;       //if game is running or not

public:
    Game() {
        gameOver = false;
        createGame();
    }

    ~Game() {
        //gets rid of unused rooms
        for (Room* room : rooms) {
            delete room;
        }
    }

    void createGame() {
        //Create The Rooms
        //EX: new Room("Name", "Description")
        Room* cafatera = new Room("Cafatrea", 
            "You are in the cafitea, you smell some lagzana");
        Room* library = new Room("Library", 
            "You're in the Library. you see an old book on the groud");
        Room* quad = new Room("Quad", 
            "You're in the quad. You see a skelliton slumed over on a bench");
        
        //add rooms to vector to assist with memory manegment
        rooms.push_back(cafatera);
        rooms.push_back(library);
        rooms.push_back(quad);

        //Connect rooms with exits
        //I cant forget to set exits both ways!
        cafeteria->setExit("NORTH", library);
        library->setExit("SOUTH", cafeteria);
        library->setExit("EAST", quad);
        quad->setExit("WEST", library);

        //Create and add crap to items
        //Format: Item{"name", "description", canPickUp, canUse}
        Item key{"KEY", "A rusty key", true, true};
        Item bench{"BENCH", "A wooden bench", false, true};
        Item book{"BOOK", "A heavy textbook", true, false};

        //acctully add items to rooms
        cafartera->addItem(key);
        quad->addItem(bench);
        library->addItem(book);

        //Set starting room
        currentRoom = cafateria;
    }

    void play() {
        printWelcome();

        //Main loop
        while (!gameOver) {
            //Print out current room info
            cout << "\n=== " << currentRoom->getName() << " ===" << endl;
            cout << currentRoom->getDescription() << endl;
            
            //print out the exits
            cout << "Exits: " << currentRoom->getExitString() << endl;
            
            //print items in room
            cout << "\nYou see:" << endl;
            vector<Item>& roomItems = currentRoom->getItems();
            if (roomItems.empty()) {
                cout << "Nothing." << endl;
            } else {
                for (Item& item : roomItems) {
                    cout << "- " << item.name << ": " << item.description << endl;
                }
            }

            //Get command
            string command;
            cout << "\nWhat would you like to do? ";
            getline(cin, command);
            
            //Process command
            processCommand(command);
        }
    }

    void processCommand(string command) {
        //Convert command to uppercase
        for (char& c : command) {
            c = toupper(c);
        }

        //commands to move around
        if (command == "NORTH" || command == "SOUTH" || command == "EAST" || command == "WEST") {
            Room* nextRoom = currentRoom->getExit(command);
            if (nextRoom != nullptr) {
                currentRoom = nextRoom;
            } else {
                cout << "You can't go that way!" << endl;
            }
        }
        //use command
        else if (command.substr(0, 4) == "USE ") {
            string itemName = command.substr(4);
            useItem(itemName);
        }
        //quit command
        else if (command == "QUIT") {
            gameOver = true;
        }
        //the help command
        else if (command == "HELP") {
            printHelp();
        }
        else {
            cout << "I don't understand that command. Type HELP for help." << endl;
        }
    }

    void useItem(string itemName) {
        Item* item = currentRoom->getItem(itemName);
        if (item == nullptr) {
            cout << "That item isn't here!" << endl;
            return;
        }

        if (!item->canUse) {
            cout << "You can't use that item!" << endl;
            return;
        }

        //add specific item use cases here
        cout << "You use the " << itemName << "." << endl;
        
        //example of specific item behavior:
        if (itemName == "KEY" && currentRoom->getName() == "Library") {
            cout << "The key unlocks a secret drawer!" << endl;
            //add more items here
        }
    }

    void printWelcome() {
        cout << "Welcome to Zuul - my cool space version!" << endl;
        cout << "Type 'HELP' for a list of commands." << endl;
    }

    void printHelp() {
    cout << "\nAvailable commands:" << endl;
        cout << "- NORTH, SOUTH, EAST, WEST : move in that direction" << endl;
        cout << "- USE [ITEM] : use an item in the current room" << endl;
        cout << "- HELP : show this help message" << endl;
        cout << "- QUIT : exit the game" << endl;
    }
    }
};

// Main function
int main() {
    Game game;
    game.play();
    return 0;
}
