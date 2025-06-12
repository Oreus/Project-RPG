#ifndef INVENTORY_H
#define INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
#include <vector>

using namespace std;

// Declaration of class Inventory
// Handles the storage and organization of objects, such as:
// Items, weapons, and armors
class Inventory {
    private:
        // Vectors for object types
        vector<Weapon*> weapons;
        vector<Armor*> armors;
        vector<Item*> items;

    public:
        // Constructor
        Inventory() : weapons(), armors(), items() {
        }
        // Getters
        vector<Weapon*> getWeapons() {
            return weapons;
        }
        vector<Armor*> getArmors() {
            return armors;
       } 
        vector<Item*> getItems() {
            return items;
       }
       // Add a weapon by pushing it into the vector "list"
       void addWeapon(Weapon* w) {
            weapons.push_back(w);
       }
       // Removes a weapon
       void removeWeapon(Weapon* w) {
            // Searches weapon index for the weapon
            for (int i = 0; i < weapons.size(); ++i) {
                if (weapons[i] == w) {
                    // uses erase to take out weapon from vector "list"
                    // Uses where the specific weapon is positioned in
                    // the vector to select it
                    weapons.erase(weapons.begin() + i);
                    break;
                }
            }
       }
       // Add an armor by pushing it into the vector "list"
       void addArmor(Armor* a) {
            armors.push_back(a);
       }
       // Same as for weapon, but for armor index instead
       void removeArmor(Armor* a) {
            for (int i = 0; i < armors.size(); ++i) {
                if (armors[i] == a) {
                    armors.erase(armors.begin() + i);
                    break;
                }
            }
        }
       // Add an item by pushing it into the vector "list"
       void addItem(Item* item) {
        items.push_back(item);
       }
       // Same as weapon and armor, but for item index
       void removeItem(Item* item) {
        for (int i = 0; i < items.size(); ++i) {
                if (items[i] == item) {
                    items.erase(items.begin() + i);
                    break;
                }
            }
       }
       // Displays all items by pulling from the item index 
       // in the inventory
        void listItems() {
            cout << "Items in inventory:" << endl;
            for (int i = 0; i < items.size(); ++i) {
                cout << i << ") " << items[i]->getName() << endl;
            }
        }
        // Same as item, but for weapons
        void listWeapons() {
            cout << "Weapons in inventory:" << endl;
            for (int i = 0; i < weapons.size(); ++i) {
                cout << i << ") " << weapons[i]->getName();
                if (weapons[i]->getStatusEffect() != nullptr) {
                    cout << " [" << weapons[i]->getStatusEffect()->getName() << "]";
                }
                cout << endl;
            }
        }
        // Same as item and weapons
        void listArmors() {
            cout << "Armors in inventory:" << endl;
            for (int i = 0; i < armors.size(); ++i) {
                cout << i << ") " << armors[i]->getName() << endl;
            }
        }
};

#endif
