#ifndef CHARACTER_H
#define CHARACTER_H
#include "StatusEffects.h"
#include <string>
#include <vector>

using namespace std;

class StatusEffect;

class Character{
    protected:
        string name;
        int level;
        int health;
        int maxHealth;
        int attackPower;
        int defense;
        int speed;
        vector<StatusEffect*> statusEffects;

    public:
        Character()
        : name(""), level(), health(), maxHealth(), attackPower(), defense(), speed(), statusEffects() {} 
        Character(string name, int level, int health, int MH, int attack, int defense, int speed);
        

        string getName();
        int getLevel();
        int getHealth();
        int getAttackPower() {
            return attackPower;
        }
        int getDefense() {
            return defense;
        }
        int getSpeed() {
            return speed;
        }

        void setLevel(int level);
        void setHealth(int h);
        void setAttackPower(int p);
        void setDefense(int d);
        void setSpeed(int s);

        void attack(Character* target);
        void takeDamage(int amount){
            health -= amount;
        }
        bool isAlive() {
            return health > 0;
        }  
        void applyStatusEffects(StatusEffect* effect);
        void processStatusEffects();
};
#endif
