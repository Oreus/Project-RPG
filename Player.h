#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"

// Declaration of class Player
// Inherits from class Character
// Manages all player specific attributes and functions
class Player : public Character {
    private:
        // Player attributes 
        int coins;
        int experience;
        int experienceToLevelUp;
        // Player gear and inventory
        Inventory* inventory;
        Weapon* weapon;
        Armor* armor;

    public:
        // Constructors
        Player(string name, int level, int health, int maxHealth, int attack, 
        int defense, int speed, int experience, int startingCoins) 
        : Character(name, level, health, maxHealth, attack, defense, speed),
        coins(startingCoins), experience(experience), experienceToLevelUp(100),
        inventory(new Inventory()), weapon(nullptr), armor(nullptr) {}

        // Getters
        int getCoins() const {
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
        // Setters
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
        // Add coins to player
        void addCoins(int amount) {
            coins += amount;
        }
        // Spend coins if player has enough
        bool spendCoins(int amount) {
            if (coins >= amount) {
                coins -= amount;
                return true;
            }
        return false;
        }
        // Adds experience to player
        void addExperience(int amount) {
            experience += amount;
            // Handles level up logic
            if (experience >= experienceToLevelUp) {
                levelUp();
            }
        }
        // Increase the player level and attributes
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
        // Equips new weapon from weapon vector index
        void equipWeapon(Weapon* w) {
            weapon = w;
        }
        // Equips new armor from armor vector index
        void equipArmor(Armor* a) {
            armor = a;
        }
        // Removes broken equipment
        void removeBrokenEquipment() {
            // References the isBroken function from the weapon class
            if (weapon && weapon->isBroken()) {
                weapon = nullptr;
            }
            // References the isBroken function from the armor class
            if (armor && armor->isBroken()) {
                armor = nullptr;
            }
        }
        // Lets player change equipment
        void changeEquipment() {
            inventory->listWeapons();
            cout << "Enter index of weapon to equip:";
            int index;
            cin >> index;
            // References the weapon vector and selects a weapon
            // using the weapon index
            vector<Weapon*> weapons = inventory->getWeapons();
            if (index >= 0 && index < weapons.size()) {
                equipWeapon(weapons[index]);
                cout << "Weapon equipped" << endl;
            }
            inventory->listArmors();
            cout << "Enter index of armor to equip:";
            cin >> index;
            // Same as weapon
            vector<Armor*> armors = inventory->getArmors();
            if (index >= 0 && index < armors.size()) {
                equipArmor(armors[index]);
                cout << "Armor equipped" << endl;
            }
        }
        // Uses an item from the inventory by referencing
        // the item vector and using the index to find and selcet it
        void useItem(int index) {
            vector<Item*> items = inventory->getItems();
            if (index >= 0 && index < items.size()) {
                items[index]->use(this);
            }
        }
        // Attacks a target, includes weapon damage if one equipped
        void attack(Character* target) {
            int damage = attackPower;
            // Takes weapon into consideration
            if (weapon) {
                damage += weapon->getDamage();
                weapon->reduceDurability();
                if (weapon->getStatusEffect() != nullptr) {
                    target->applyStatusEffects(weapon->getStatusEffect());
                }
            }
            target->takeDamage(damage);
        }
        //Takes damage, includes armor if one equipped
        void takeDamage(int amount) {
            int reduced = amount;
            // Takes armor into consideration
            if (armor) {
                reduced -= armor->getDefenseBoost();
                armor->reduceDurability();
            }
            if (reduced < 0) reduced = 0;
            health -= reduced;
        }
        // Checks if player is alive
        bool isAlive() {
            return health > 0;
        }
        // Applies a status effect
        void applyStatusEffects(StatusEffect* effect) {
            statusEffects.push_back(effect);
        }
        // Processes any and all active status effects
        void processStatusEffects() {
            for (int i = 0; i < statusEffects.size(); ++i) {
                statusEffects[i]->applyEffect(this);
                statusEffects[i]->update();
                if (statusEffects[i]->isExpired()) {
                    // Takes away status effect if its duration is over
                    // Erases it from the vector by finding it with begin
                    statusEffects.erase(statusEffects.begin() + 1);
                    i--;
                }
            }
        }
};

#endif
