#ifndef BOMB_H
#define BOMB_H
#include <string>
#include "Item.h"
#include "Character.h"

using namespace std;

// Declaration of class Bomb
// handles the attributes and uses of Bombs
// Inherits from class Item
class Bomb : public Item {
    private:
        // Amount of damage bomb does
        int damageAmount;

    public:
        // Comstructors
        Bomb()
        : Item(), damageAmount() {}
        Bomb(string name, int damageAmount) 
        : Item(name), damageAmount(damageAmount) {}
        // Uses bomb
        void use(Character* target) {
        if (target != nullptr) {
        target->takeDamage(damageAmount);
        }
    }
};

#endif
