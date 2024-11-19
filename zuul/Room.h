#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room {
private:
    string name;        //name of the room
    string description; //description
    map<string, Room*> exits; // exits
    vector<Item> items; // Items thjat can be found in the room

public:
    // Constructor
    Room(string roomName, string roomDesc) {
        name = roomName;
        description = roomDesc;
    }

    // add exit to room
    void setExit(string direction, Room* nextRoom) {
        exits[direction] = nextRoom;
    }

    // go in given dicrecvtion
    Room* getExit(string direction) {
        if (exits.find(direction) != exits.end()) {
            return exits[direction];
        }
        return nullptr;
    }

    //Add item to room
    void addItem(Item item) {
        items.push_back(item);
    }

    //Remove item from room
    bool removeItem(string itemName) {
        for (int i = 0; i < items.size(); i++) {
            if (items[i].name == itemName) {
                items.erase(items.begin() + i);
                return true;
            }
        }
        return false;
    }

    // Check if room has specific item
    bool hasItem(string itemName) {
        for (const Item& item : items) {
            if (item.name == itemName) {
                return true;
            }
        }
        return false;
    }

    // Get item properties (returns nullptr if item not found)
    Item* getItem(string itemName) {
        for (Item& item : items) {
            if (item.name == itemName) {
                return &item;
            }
        }
        return nullptr;
    }

    //the getters
    string getDescription() { return description; }
    string getName() { return name; }
    vector<Item>& getItems() { return items; }
    
    //Get list of available exits
    string getExitString() {
        string exitList = "";
        for (auto const& exit : exits) {
            exitList += exit.first + " ";
        }
        return exitList;
    }
};

#endif
