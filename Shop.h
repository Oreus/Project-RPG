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

class Shop {
    private:
        vector<Item*> inventory;
        vector<Weapon*> weaponStock;
        vector<Armor*> armorStock;

    public:
        Shop() : inventory(), weaponStock(), armorStock() {}

        void displayItem() {
            cout << "Shop Inventory:" << endl;
            for (int i = 0; i < inventory.size(); ++i) {
                cout << i << ") Item: " << inventory[i]->getName() << endl;
            }
            for (int i = 0; i < weaponStock.size(); ++i) {
                cout << i + inventory.size() << ") Weapon: " << weaponStock[i]->getName() << endl;
            }
            for (int i = 0; i < armorStock.size(); ++i) {
                cout << i + inventory.size() + weaponStock.size() << ") Weapon: " << armorStock[i]->getName() << endl;
            }
        }
        bool buyItem(int index, Player* player) {
            const int price = 50;
            if (player->getCoins() < price) {
            cout << "You don't have enough coins to buy this item!" << endl;
            return false;
            }
            if (index < inventory.size()) {
                player->getInventory()->addItem(inventory[index]);
                return true;
            }
            index -= inventory.size();
            if (index < weaponStock.size()) {
                player->getInventory()->addWeapon(weaponStock[index]);
                return true;
            }
            index -= weaponStock.size();
            if (index < armorStock.size()) {
                player->getInventory()->addArmor(armorStock[index]);
                return true;
            }
            return false;
        }
        void updateInventory(int playerLevel) {
            inventory.push_back(new HealingPotion("Potion Lvl" + to_string(playerLevel), 10+ playerLevel));
            weaponStock.push_back(new Weapon("Sword Lvl" + to_string(playerLevel), 5, 10 + playerLevel, 10, 10 + playerLevel, nullptr));
            armorStock.push_back(new Armor("Armor Lvl" + to_string(playerLevel), 5 + playerLevel, 10, 10 + playerLevel));
            }
};

#endif