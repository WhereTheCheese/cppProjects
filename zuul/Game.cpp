#include <iostream>
#include <vector>
#include "Room.h"
using namespace std;

class Game {
private:
    vector<Room*> rooms;  
    vector<Item> inventory; // Added inventory for player
    Room* currentRoom;    //where you curretnly are in the game, liek the room
    bool gameOver;       //if game is running or not
    bool hasWon;        //tracks if player has won

public:
    Game() {
        gameOver = false;
        hasWon = false;
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
        Room* cafeteria = new Room("Cafeteria", "You are in the cafeteria, it's eerily quiet");
        Room* medbay = new Room("Medbay", "The medbay is dimly lit with medical equipment scattered around");
        Room* electrical = new Room("Electrical", "Sparks fly from exposed wires in the electrical room");
        Room* engine_room = new Room("Engine_Room", "The engine hums with a low vibration");
        Room* hallway_1 = new Room("Hallway_1", "A long corridor stretches before you");
        Room* navigation = new Room("Navigation", "Star maps and control panels fill the navigation room");
        Room* comms = new Room("Comms", "Communication equipment lines the walls");
        Room* gaming_room = new Room("Gaming_Room", "Various gaming consoles are scattered about");
        Room* hallway_2 = new Room("Hallway_2", "Another long corridor with flickering lights");
        Room* empty_room = new Room("Empty_Room", "A stark empty room with just some basic furniture");
        Room* airlock = new Room("Airlock", "The airlock door looks sturdy and well-secured");
        Room* gym = new Room("Gym", "Exercise equipment fills this room");
        Room* room_1 = new Room("1", "A small storage room");
        Room* room_2 = new Room("2", "Another storage area");
        Room* room_3 = new Room("3", "The final storage room");

        //add rooms to vector
        rooms.push_back(cafeteria);
        rooms.push_back(medbay);
        rooms.push_back(electrical);
        rooms.push_back(engine_room);
        rooms.push_back(hallway_1);
        rooms.push_back(navigation);
        rooms.push_back(comms);
        rooms.push_back(gaming_room);
        rooms.push_back(hallway_2);
        rooms.push_back(empty_room);
        rooms.push_back(airlock);
        rooms.push_back(gym);
        rooms.push_back(room_1);
        rooms.push_back(room_2);
        rooms.push_back(room_3);

        //Connect rooms with exits
        cafeteria->setExit("WEST", medbay);
        cafeteria->setExit("EAST", electrical);
        cafeteria->setExit("SOUTH", engine_room);
        
        medbay->setExit("EAST", cafeteria);
        
        electrical->setExit("WEST", cafeteria);
        
        engine_room->setExit("WEST", hallway_1);
        engine_room->setExit("EAST", hallway_2);
        engine_room->setExit("NORTH", cafeteria);
        
        hallway_1->setExit("WEST", navigation);
        hallway_1->setExit("EAST", engine_room);
        
        navigation->setExit("EAST", hallway_1);
        navigation->setExit("SOUTH", comms);
        
        comms->setExit("NORTH", navigation);
        comms->setExit("EAST", gaming_room);
        
        gaming_room->setExit("EAST", gym);
        gaming_room->setExit("WEST", comms);
        gaming_room->setExit("NORTH", hallway_2);
        gaming_room->setExit("SOUTH", room_1);
        
        hallway_2->setExit("SOUTH", gaming_room);
        hallway_2->setExit("WEST", engine_room);
        hallway_2->setExit("EAST", empty_room);
        
        empty_room->setExit("WEST", hallway_2);
        empty_room->setExit("SOUTH", gym);
        empty_room->setExit("EAST", airlock);
        
        airlock->setExit("WEST", empty_room);
        
        gym->setExit("NORTH", empty_room);
        gym->setExit("WEST", gaming_room);
        
        room_1->setExit("NORTH", gaming_room);
        room_1->setExit("SOUTH", room_2);
        
        room_2->setExit("NORTH", room_1);
        room_2->setExit("SOUTH", room_3);
        
        room_3->setExit("NORTH", room_2);

        //Create and add items
        Item key{"KEY", "A mysterious key with medical symbols", true, true};
        Item lockpick{"LOCKPICK", "A professional lock picking set", true, true};
        Item chair{"CHAIR", "A comfortable looking chair", false, true};
        Item table{"TABLE", "A sturdy metal table", false, true};
        Item bench{"BENCH", "A wooden bench", false, true};

        //add items to rooms
        gaming_room->addItem(key);
        medbay->addItem(table);
        cafeteria->addItem(chair);
        navigation->addItem(bench);
        empty_room->addItem(table);

        //Set starting room
        currentRoom = cafeteria;
    }

    void processCommand(string command) {
        //Convert command to uppercase
        for (char& c : command) {
            c = toupper(c);
        }

        //Parse command for TAKE and DROP
        if (command.substr(0, 5) == "TAKE ") {
            string itemName = command.substr(5);
            takeItem(itemName);
            return;
        }
        if (command.substr(0, 5) == "DROP ") {
            string itemName = command.substr(5);
            dropItem(itemName);
            return;
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
        //inventory command
        else if (command == "INVENTORY") {
            showInventory();
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

    void takeItem(string itemName) {
        Item* item = currentRoom->getItem(itemName);
        if (item == nullptr) {
            cout << "That item isn't here!" << endl;
            return;
        }
        if (!item->canPickUp) {
            cout << "You can't pick that up!" << endl;
            return;
        }
        inventory.push_back(*item);
        currentRoom->removeItem(itemName);
        cout << "Taken." << endl;
    }

    void dropItem(string itemName) {
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].name == itemName) {
                currentRoom->addItem(inventory[i]);
                inventory.erase(inventory.begin() + i);
                cout << "Dropped." << endl;
                return;
            }
        }
        cout << "You don't have that item!" << endl;
    }

    void showInventory() {
        if (inventory.empty()) {
            cout << "Your inventory is empty." << endl;
            return;
        }
        cout << "You are carrying:" << endl;
        for (const Item& item : inventory) {
            cout << "- " << item.name << ": " << item.description << endl;
        }
    }

    void useItem(string itemName) {
        // First check inventory
        bool inInventory = false;
        for (const Item& item : inventory) {
            if (item.name == itemName) {
                inInventory = true;
                break;
            }
        }
        
        if (!inInventory) {
            cout << "You don't have that item!" << endl;
            return;
        }

        // Game winning logic
        if (itemName == "KEY" && currentRoom->getName() == "Medbay") {
            cout << "You use the key to open a locked cabinet, revealing a lock pick set!" << endl;
            Item lockpick{"LOCKPICK", "A professional lock picking set", true, true};
            currentRoom->addItem(lockpick);
        }
        else if (itemName == "LOCKPICK" && currentRoom->getName() == "Airlock") {
            cout << "You successfully pick the airlock lock. You've won the game!" << endl;
            hasWon = true;
            gameOver = true;
        }
        else {
            cout << "Nothing interesting happens." << endl;
        }
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

        if (hasWon) {
            cout << "\nCongratulations! You've escaped through the airlock!" << endl;
        }
    }

    void printWelcome() {
        cout << "Welcome to Space Station Zuul!" << endl;
        cout << "Find a way to escape through the airlock." << endl;
        cout << "Type 'HELP' for a list of commands." << endl;
    }

    void printHelp() {
        cout << "\nAvailable commands:" << endl;
        cout << "- NORTH, SOUTH, EAST, WEST : move in that direction" << endl;
        cout << "- TAKE [ITEM] : pick up an item" << endl;
        cout << "- DROP [ITEM] : drop an item" << endl;
        cout << "- USE [ITEM] : use an item" << endl;
        cout << "- INVENTORY : show your inventory" << endl;
        cout << "- HELP : show this help message" << endl;
        cout << "- QUIT : exit the game" << endl;
    }
};

// Main function
int main() {
    Game game;
    game.play();
    return 0;
}
