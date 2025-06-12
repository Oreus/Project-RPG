#ifndef ITEM_H
#define ITEM_H
#include "Character.h"
#include <string>

using namespace std;

// Declaration of class Item
// This class is an abstract class that is a base for
// HealingPotion and Bomb
class Item {
    private:
        // Name of the item
        string name;
    
    public:
    // Constructors
    Item()
    : name() {}
    Item(string name)
    : name(name) {}
    //Getter
    string getName() {
        return name;
    }
    // Virtual method for the use of the weapon
    // is meant to be overriden by the items
    virtual void use(Character* target) = 0;
};

#endif
