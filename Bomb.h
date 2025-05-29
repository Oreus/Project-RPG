#ifndef BOMB_H
#define BOMB_H
#include <string>
#include "Item.h"
#include "Character.h"

using namespace std;

class Bomb : public Item {
    private:
        int damageAmount;

    public:
        Bomb()
        : Item(), damageAmount() {}
        Bomb(string name, int damageAmount);

    void use(Character* target);
};

#endif
