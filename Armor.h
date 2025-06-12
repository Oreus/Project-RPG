#ifndef ARMOR_H
#define ARMOR_H
#include <string>

using namespace std;

// Declaration of class Armor
// Handles the attributes and uses of armors
class Armor {
    private:
        // Armor attributes
        string name;
        int defenseBoost;
        int durability;
        int maxDurability;
    
    public:
        // Constructors
        Armor() : name(""), defenseBoost(0), durability(0), maxDurability(0) {}
        Armor(string nombre, int defense, int dur, int maxDur) 
        : name(nombre), defenseBoost(defense), durability(dur), 
        maxDurability(maxDur) {}

        // Getters
        string getName() {
            return name;
        }
        int getDefenseBoost() {
            return defenseBoost;
        }
        int getDurability() {
            return durability;
        }
        int getMaxDurability() {
            return maxDurability;
        }
        // Setters
        void setName(string nombre) {
            name = nombre;
        }
        void setDefenseBoost(int defense) {
            defenseBoost = defense;
        }
        void setDurability(int dur) {
            durability = dur;
        }
        void setMaxDurability(int maxDur) {
            maxDurability = maxDur;
        }
        // Reduces durability
        void reduceDurability() {
            if (durability > 0) {
                durability -= 1;
            }
        }
        // Checks if the armor is broken
        bool isBroken() {
            return durability <= 0;
        }
};

#endif
