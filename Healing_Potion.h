#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H
#include <string>
#include "Item.h"
#include "Character.h"

using namespace std;

// Declaration of class HealingPotion
// Handles the attribute and uses of Healing Potions
// Inherits from class Item
class HealingPotion : public Item {
    private:
        // Amount of healing potion does
        int healingAmount;
    
    public:
        // Constructors
        HealingPotion() 
        : Item(), healingAmount() {}
        HealingPotion(string name, int healingAmount)
        : Item(name), healingAmount(healingAmount) {}
        // Uses healing potion to restore health
        void use(Character* target) {
            // Checks if target IS there
            if (target != nullptr) {
        int newHealth = target->getHealth() + healingAmount;
        target->setHealth(newHealth);
        }
    }
};

#endif
