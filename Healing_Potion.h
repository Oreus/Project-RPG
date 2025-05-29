#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H
#include <string>
#include "Item.h"
#include "Character.h"

using namespace std;

class HealingPotion : public Item {
    private:
        int healingAmount;
    
    public:
        HealingPotion() 
        : Item(), healingAmount() {}
        HealingPotion(string name, int healingAmount);

        void use(Character* target);
};

#endif
