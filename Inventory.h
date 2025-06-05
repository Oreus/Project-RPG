#ifndef INVENTORY_H
#define INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
#include <vector>

using namespace std;

class Inventory {
    private:
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Item*> items;

    public:
        Inventory() : weapons(), armors(), items() {
        }

        vector<Weapon*> getWeapons() {
            return weapons;
        }
        vector<Armor*> getArmors() {
            return armors;
       } 
        vector<Item*> getItems() {
            return items;
       }
       void addWeapon(Weapon* w) {
            weapons.push_back(w);
       }
       void removeWeapon(Weapon* w) {
            for (int i = 0; i < weapons.size(); ++i) {
                if (weapons[i] == w) {
                    weapons.erase(weapons.begin() + i);
                    break;
                }
            }
       }
       void addArmor(Armor* a) {
            armors.push_back(a);
       }
       void removeArmor(Armor* a) {
            for (int i = 0; i < armors.size(); ++i) {
                if (armors[i] == a) {
                    armors.erase(armors.begin() + 1);
                    break;
                }
            }
        }
       void addItem(Item* item) {
        items.push_back(item);
       }
       void removeItem(Item* item) {
        for (int i = 0; i < items.size(); ++i) {
                if (items[i] == item) {
                    items.erase(items.begin() + i);
                    break;
                }
            }
       }
        void listItems() {
            cout << "Items in inventory:" << endl;
            for (int i = 0; i < items.size(); ++i) {
                cout << "- " << items[i]->getName() << endl;
            }
        }
        void listWeapons() {
            cout << "Weapons in inventory:" << endl;
            for (int i = 0; i < weapons.size(); ++i) {
                cout << "- " << weapons[i]->getName() << endl;
            }
        }
        void listArmors() {
            cout << "Armors in inventory:" << endl;
            for (int i = 0; i < armors.size(); ++i) {
                cout << "- " << armors[i]->getName() << endl;
            }
        }
};

#endif