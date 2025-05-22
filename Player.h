#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"


class Player : public Character {
    private:
        int coins;
        int experience;
        int experienceToLevelUp;
        Inventory* inventory;
        Weapon* weapon;
        Armor* armor;

    public:
        Player(string name, int level, int health, int attack, int defense, int speed, int experience, int coins);

        ~Player();

        int getCoins();
        int getExperience();
        Weapon* getEquippedWeapon();
        Armor* getEquippedArmor();
        Inventory* getInventory();

        void setCoins(int c);
        void setExperience(int e);
        void setEquippedWeapon(Weapon* w);
        void setEquippedArmor(Armor* a);

        void addCoins(int amount);
        bool spendCoins(int amount);
        void addExperience(int amount);
        void levelUp();
        void equipWeapon(Weapon* w);
        void equipArmor(Armor* a);
        void removeBrokenEquipment();
        void changeEquipment();
        void useItem(int index);
        void attack(Character* target);
        void takeDamage(int amount);
        bool isAlive();  
        void applyStatusEffects(StatusEffect* effect);
        void processStatusEffects();
};

#endif