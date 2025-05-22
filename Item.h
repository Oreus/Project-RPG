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

    virtual ~Item() {}

    string getName() {
        return name;
    }

    void use(Character* target);
};

#endif