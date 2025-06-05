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
        Character(string name, int level, int health, int MH, int attack, int defense, int speed)
        : name(name), level(level), health(health), maxHealth(MH), attackPower(attack), defense(defense), speed(speed), statusEffects() {}
        

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
        void attack(Character* target) {
            target->takeDamage(attackPower);
        }
        void takeDamage(int amount){
            health -= amount;
        }
        bool isAlive() {
            return health > 0;
        }  
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
