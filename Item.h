#ifndef ITEM_H
#define ITEM_H
#include "Character.h"
#include <string>

using namespace std;

class Item {
    private:
        string name;
    
    public:
    Item()
    : name() {}
    Item(string name)
    : name(name) {}

    string getName() {
        return name;
    }

    virtual void use(Character* target){
    }
};

#endif
