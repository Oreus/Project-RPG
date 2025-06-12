#ifndef CHARACTER_H
#define CHARACTER_H
#include "StatusEffects.h"
#include <string>
#include <vector>

using namespace std;

class StatusEffect;

// Declaration of class Character
// This class is a abstract class that is a base 
// for player and monster
class Character{
    protected:
        // Declaration of attributes that all characters share
        string name;
        int level;
        int health;
        int maxHealth;
        int attackPower;
        int defense;
        int speed;
        // For taking into account a status effect on a character
        vector<StatusEffect*> statusEffects;

    public:
        // Constructors
        Character()
        : name(""), level(), health(), maxHealth(), attackPower(), defense(), speed(), statusEffects() {} 
        Character(string name, int level, int health, int MH, int attack, int defense, int speed)
        : name(name), level(level), health(health), maxHealth(MH), attackPower(attack), defense(defense), speed(speed), statusEffects() {}
        
        // Getters
        string getName() {
            return name;
        }
        int getLevel() {
            return level;
        }
        int getHealth() {
            return health;
        }
        int getAttackPower() {
            return attackPower;
        }
        int getDefense() {
            return defense;
        }
        int getSpeed() {
            return speed;
        }
        // Setters
        void setLevel(int l) {
            level = l;
        }
        void setHealth(int h) {
            health  =  h;
        }
        void setAttackPower(int p) {
            attackPower = p;
        }
        void setDefense(int d) {
            defense = d;
        }
        void setSpeed(int s) {
            speed = s;
        }
        // Basic combat necessary methods
        void attack(Character* target) {
            target->takeDamage(attackPower);
        }
        void takeDamage(int amount){
            health -= amount;
        }
        bool isAlive() {
            return health > 0;
        }  
        // Managment of staus effects
        void applyStatusEffects(StatusEffect* effect) {
            statusEffects.push_back(effect);
        }
        void processStatusEffects() {
            for (int i = 0; i < statusEffects.size(); ++i) {
            statusEffects[i]->applyEffect(this);
            statusEffects[i]->update();
            if (statusEffects[i]->isExpired()) {
                statusEffects.erase(statusEffects.begin() + i);
                i--;
            }
        }
    }
};

#endif
