#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"
#include "Healing_Potion.h"

using namespace std;

// Declaration of class Shop
// Handles the actual mechanics and logic of the shop
class Shop {
    private:
        // Vectors for storing the items
        vector<Item*> inventory;
        vector<Weapon*> weaponStock;
        vector<Armor*> armorStock;

    public:
        // Constructor
        Shop() : inventory(), weaponStock(), armorStock() {}

        // Displays the items
        void displayItem() {
            cout << "Shop Inventory:" << endl;
            // Shows all of the Item type objects within the Inventory vector 
            // by using the size of the size of the vector as parameters and looping through
            // They are accesed by index, which in this case is: inventory[i]
            for (int i = 0; i < inventory.size(); ++i) {
                cout << i << ") Item: " << inventory[i]->getName() << endl;
            }
            // Loops through the weaponStock vector with the same method
            for (int i = 0; i < weaponStock.size(); ++i) {
                // The display index is "pushed" by inventory.size so the weaopon index
                // is displayed after items
                cout << (i + inventory.size()) << ") Weapon: " << weaponStock[i]->getName();
                if (weaponStock[i]->getStatusEffect() != nullptr) {
                    cout << " [" << weaponStock[i]->getStatusEffect()->getName() << "]";
                }
                cout << endl;
            }
            // Loops through the armorStock vector
            for (int i = 0; i < armorStock.size(); ++i) {
                // Same method of "pushing" the display index, so armors appear after 
                // items and weapons
                cout << (i + inventory.size() + weaponStock.size()) << ") Armor: " << armorStock[i]->getName() << endl;
            }
        }
        // Handles the purchase of objects by a player, uses an index and
        // updates the players inventory on purchase
        bool buyItem(int index, Player* player) {
            // Assumes all prices are at a constant 50
            const int price = 50;
            if (!player->spendCoins(price)) {
            cout << "You don't have enough coins to buy this item!" << endl;
            return false;
            }
            // Determines the type of object using the index
            if (index < inventory.size()) {
                player->getInventory()->addItem(inventory[index]);
                return true;
            }
            // Moves the "search" within the index onto the next vector type
            index -= inventory.size();
            if (index < weaponStock.size()) {
                player->getInventory()->addWeapon(weaponStock[index]);
                return true;
            }
            // Moves the "search" within the index onto the next vector type
            index -= weaponStock.size();
            if (index < armorStock.size()) {
                player->getInventory()->addArmor(armorStock[index]);
                return true;
            }
            // If index is invalid
            cout << "Invalid item index" << endl;
            return false;

            cout << "Purchase succesful, your new coin total is: "
            << player->getCoins() << " coins." << endl;
            return true;
            
        }
        // Updates the inventory of the shop to match the current player level
        void updateInventory(int playerLevel) {
            // Adds a new healing potion to shop inventory based on player level
            // the name of the potion updates based on level, as well as scales the potion power to the level 
            inventory.push_back(new HealingPotion("Potion Lvl" + to_string(playerLevel), 10+ playerLevel));
            // Adds a new bomb to shop inventory based on player level
            // the name of the bomb updates based on level, as well as scales the bomb power to the level 
            inventory.push_back(new Bomb("Bomb Lvl" + to_string(playerLevel), 10+ playerLevel));
            // Adds new weapons that also scales with player level, min damage stays the same
            // max damage scales, durability stays, max durability scales, nullptr is for a status effect
            weaponStock.push_back(new Weapon("Sword Lvl" + to_string(playerLevel), 5, 10 + playerLevel, 10, 10 + playerLevel, nullptr));
            // Adds new aemors that scale with player level, defense scales, durability stays, and max durability scales
            armorStock.push_back(new Armor("Armor Lvl" + to_string(playerLevel), 5 + playerLevel, 10, 10 + playerLevel));
            }
};

#endif
