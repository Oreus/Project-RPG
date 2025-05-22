#include "Character.h"

Character::Character(string name, int level, int health, int MH, int attack, int defense, int speed)
    : name(name), level(level), health(health), maxHealth(MH), attackPower(attack), defense(defense), speed(speed) {}

    string Character::getName() {
    return name;
}
    int Character::getLevel() {
    return level;
}
    int Character::getHealth() {
    return health;
}