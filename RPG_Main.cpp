#include "Armor.h"
#include "Bomb.h"
#include "Character.h"
#include "Game.h"
#include "Healing_Potion.h"
#include "Inventory.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Poison.h"
#include "Shop.h"
#include "StatusEffects.h"
#include "Stun.h"
#include "Weapon.h"
#include <iostream>

using namespace std;

int main() {
    // Previous code for showing proper class functions:

    ///Monster Dragon("Dragon", 13, 30, 28, 38, 13, 25, 13, 5.2);
    ///cout << "Monster created!" << endl;
    ///cout << "Name: " << Dragon.getName() << endl;
    ///cout << "Level: " << Dragon.getLevel() << endl;
    ///cout << "Health: " << Dragon.getHealth() << endl;

    ///Monster* enemy = new Monster("Goblin", 3, 40, 40, 15, 5, 10, 10, 1.5);
    ///cout << "Initial Goblin health: " << enemy->getHealth() << endl;
    
    ///Item* potion = new HealingPotion("Minor Potion", 15);
    ///Item* bomb = new Bomb("Fire Bomb", 20);

    ///potion->use(enemy);  
    ///cout << "After using potion: " << enemy->getHealth() << endl;

    ///bomb->use(enemy);
    ///cout << "After using bomb: " << enemy->getHealth() << endl;
    ///return 0;

    // Main game
    Game game;
    game.start();
    return 0;
};
