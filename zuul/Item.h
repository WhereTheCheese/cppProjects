#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

// Simple struct for items
struct Item {
    string name;        //NAME OF item
    string description; // Description
    bool canPickUp;     //fi item can be picked up
    bool canUse;        //if item can be used
};

#endif
