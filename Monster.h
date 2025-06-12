#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"

// Declaration of class Monster
// Inherits from class Character
class Monster : public Character{
    private:
    // Monster attributes
        int dropCoins;
        float difficultyFactor;
    
    public:
        // Constructors
        Monster()
        : Character(), dropCoins(), difficultyFactor() {}
        Monster(string name, int level, int health, 
        int MH, int attack, int defense, int speed, int dropCoins, float difficultyFactor)
        : Character(name, level, health, MH, attack, 
        defense, speed), dropCoins(dropCoins), difficultyFactor(difficultyFactor) {}
        // Getters
        int getDropCoins(){
            return dropCoins;
        }
        // Used to interpret the difficulty factor into how many turns the monster gets
        // against the player
        int getTurnsAgainstPlayer() {
            return static_cast<int>(difficultyFactor);
        }
};

#endif
