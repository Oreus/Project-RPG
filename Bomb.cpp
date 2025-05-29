#include "Bomb.h"

Bomb::Bomb(string name, int damageAmount)
    : Item(name), damageAmount(damageAmount) {}

void Bomb::use(Character* target) {
    if (target != nullptr) {
        target->takeDamage(damageAmount);
    }
}