#include "Monster.h"

Monster::Monster(string name, int level, int health, int MH, int attack, int defense, int speed, int dropCoins, float difficultyFactor)
    : Character(name, level, health, MH, attack, defense, speed), dropCoins(dropCoins), difficultyFactor(difficultyFactor) {
}