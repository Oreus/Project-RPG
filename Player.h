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
        Player(string name, int level, int health, int maxHealth, int attack, int defense, int speed, int experience, int coins) 
        : Character(name, level, health, maxHealth, attack, defense, speed),
        coins(coins), experience(experience), experienceToLevelUp(100),
        inventory(new Inventory()), weapon(nullptr), armor(nullptr) {}

        ~Player();

        int getCoins() {
            return coins;
        }
        int getExperience() {
            return experience;
        }
        Weapon* getEquippedWeapon() {
            return weapon;
        }
        Armor* getEquippedArmor() {
            return armor;
        }
        Inventory* getInventory() {
            return inventory;
        }
        void setCoins(int c) {
            coins = c;
        }
        void setExperience(int e) {
            experience = e;
        }
        void setEquippedWeapon(Weapon* w) {
            weapon = w;
        }
        void setEquippedArmor(Armor* a) {
            armor = a;
        }

        void addCoins(int amount) {
            coins += amount;
        }
        bool spendCoins(int amount) {
            if (coins >= amount) {
                coins -= amount;
                return true;
            }
        return false;
        }
        void addExperience(int amount) {
            experience += amount;
            if (experience >= experienceToLevelUp) {
                levelUp();
            }
        }
        void levelUp() {
            level++;
            experience = 0;
            experienceToLevelUp += 50;
            maxHealth += 10;
            health = maxHealth;
            attackPower += 5;
            defense += 3;
            speed += 1;
        }
        void equipWeapon(Weapon* w) {
            weapon = w;
        }
        void equipArmor(Armor* a) {
            armor = a;
        }
        void removeBrokenEquipment() {
            if (weapon && weapon->isBroken()) {
                weapon = nullptr;
            }
            if (armor && armor->isBroken()) {
                armor = nullptr;
            }
        }
        void changeEquipment() {
            inventory->listWeapons();
            cout << "Enter index of weapon to equip:";
            int index;
            cin >> index;
            vector<Weapon*> weapons = inventory->getWeapons();
            if (index >= 0 && index < weapons.size()) {
                equipWeapon(weapons[index]);
                cout << "Weapon equipped" << endl;
            }
            inventory->listArmors();
            cout << "Enter index of armor to equip:";
            cin >> index;
            vector<Armor*> armors = inventory->getArmors();
            if (index >= 0 && index < armors.size()) {
                equipArmor(armors[index]);
                cout << "Armor equipped" << endl;
            }
        }

        void useItem(int index) {
            vector<Item*> items = inventory->getItems();
            if (index >= 0 && index < items.size()) {
                items[index]->use(this);
            }
        }
        void attack(Character* target) {
            int damage = attackPower;
            if (weapon) {
                damage += weapon->getDamage();
                weapon->reduceDurability();
                if (weapon->getStatusEffect() != nullptr) {
                    target->applyStatusEffects(weapon->getStatusEffect());
                }
            }
            target->takeDamage(damage);
        }
        void takeDamage(int amount) {
            int reduced = amount;
            if (armor) {
                reduced -= armor->getDefenseBoost();
                armor->reduceDurability();
            }
            if (reduced < 0) reduced = 0;
            health -= reduced;
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
                    statusEffects.erase(statusEffects.begin() + 1);
                    i--;
                }
            }
        }
};

#endif
