#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include "StatusEffects.h"

using namespace std;

class Weapon {
    private:
        string name;
        int minDamage;
        int maxDamage;
        int durability;
        int maxDurability;
        StatusEffect* statusEffect;

    public:
        Weapon() : name(""), minDamage(0), maxDamage(0), durability(0), maxDurability(0), statusEffect(nullptr) {};
        Weapon(string nombre, int min, int max, int dur, int maxDur, StatusEffect* SE) {}
        
        string getName(){
            return name;
        }
        int getMinDamage() {
            return minDamage;
        }
        int getMaxDamage() {
            return maxDamage;
        }
        int getDamage(){
            return minDamage + (rand()%(maxDamage - minDamage + 1));
        }
        int getDuarbility(){
            return durability;
        }
        int getMaxDurability(){
            return maxDurability;
        }
        StatusEffect* getStatusEffect() {
            return statusEffect;
        }
        void setDurability(int dur) {
            durability = dur;
        }
        void setName(string nombre) {
            name = nombre;
        }
        void setMinDamage(int min) {
            minDamage = min;
        }
        void setMaxDamage(int max) {
            maxDamage = max;
        }
        void setStatusEffect(StatusEffect* effect) {
            statusEffect = effect;
        }
        void setMaxDurability(int maxDur) {
            maxDurability = maxDur;
        }
        void applyStatusEffect(Character* target){
            if (statusEffect != nullptr){
                (*statusEffect).applyEffect(target);
            }
        }
        void reduceDurability() {
            if (durability > 0) {
                durability = durability - 1;
            }
        }
        bool isBroken() {
            return durability <= 0;
        }
};

#endif