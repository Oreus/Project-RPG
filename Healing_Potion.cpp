#include "Healing_Potion.h"

HealingPotion::HealingPotion(string name, int healingAmount)
    : Item(name), healingAmount(healingAmount) {}

void HealingPotion::use(Character* target) {
    if (target != nullptr) {
        int newHealth = target->getHealth() + healingAmount;
        target->setHealth(newHealth);
    }
}