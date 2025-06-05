#ifndef ARMOR_H
#define ARMOR_H
#include <string>

using namespace std;

class Armor {
    private:
        string name;
        int defenseBoost;
        int durability;
        int maxDurability;
    
    public:
        Armor() : name(""), defenseBoost(0), durability(0), maxDurability(0) {}
        Armor(string nombre, int defense, int dur, int maxDur) {}

        string getName() {
            return name;
        }
        int getDefenseBoost() {
            return defenseBoost;
        }
        int getDurability() {
            return durability;
        }
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
        void reduceDurability() {
            if (durability > 0) {
                durability = - 1;
            }
        }
        bool isBroken() {
            return durability <= 0;
        }
};

#endif