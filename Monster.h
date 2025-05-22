#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"

class Monster : public Character{
    private:
        int dropCoins;
        float difficultyFactor;
    
    public:
        Monster()
        : Character(), dropCoins(), difficultyFactor() {}
        Monster(string name, int level, int health, int MH, int attack, int defense, int speed, int dropCoins, float difficultyFactor);

        int getDropCoins(){
            return dropCoins;
        }
        int getTurnsAgainstPlayer();
};

#endif