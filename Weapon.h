#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include "StatusEffects.h"

using namespace std;

// Declaration of class Weapon
// Handles the attrubutes and uses of weapons
class Weapon {
    private:
        // Weapon attributes
        string name;
        int minDamage;
        int maxDamage;
        int durability;
        int maxDurability;
        StatusEffect* statusEffect;

    public:
        // Constructors
        Weapon() : name(""), minDamage(0), maxDamage(0), durability(0), 
        maxDurability(0), statusEffect(nullptr) {};
        Weapon(string nombre, int min, int max, 
        int dur, int maxDur, StatusEffect* SE) : 
        name(nombre), minDamage(min), maxDamage(max), 
        durability(dur), maxDurability(maxDur), statusEffect(SE)
{}
        
        // Getters
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
        // Gets from the status Effect class what the status effect
        // on the weapon does
        StatusEffect* getStatusEffect() {
            return statusEffect;
        }
        // Setters
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
        // Applys status effects
        void applyStatusEffect(Character* target){
            // Looks to see if there IS (!= nullptr, meaning not null) 
            // a status effect
            if (statusEffect != nullptr){
                (*statusEffect).applyEffect(target);
            }
        }
        // Reduces durability when used
        void reduceDurability() {
            if (durability > 0) {
                durability = durability - 1;
            }
        }
        // Checks if the weapon is broken
        bool isBroken() {
            return durability <= 0;
        }
};

#endif
