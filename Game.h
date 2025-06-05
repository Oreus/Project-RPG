#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Monster.h"
#include "Shop.h"

using namespace std;

class Game {
    private:
        Player* player;
        Monster* currentMonster;
        Shop* shop;
        int level;
        bool gameOver;

    public:
        Game() : player(nullptr), currentMonster(nullptr),
        shop(new Shop()), level(1), gameOver(false) {}

        ~Game() {}

        void handleShop() {
            cout << "\n--- Shop ---" << endl;
            shop->displayItem();
            cout << "Enter the number of the item to buy (-1 to exit): ";
            int choice;
            while (true) {
                cin >> choice;
                if (choice == -1) break;
                if (!shop->buyItem(choice, player)) {
                    cout << "Invalid selection." << endl;
                }
                cout << "Buy another item? (-1 to exit): ";
            }
            cout << "\nWould you like to change equipment? (1 = yes, 0 = no): ";
            int change;
            cin >> change;
            if (change == 1) {
                player->changeEquipment();
            }
        }
        void battleLoop() {
            cout << "\nA " << currentMonster->getName() << " appeared!" << endl;
            while (player->isAlive() && currentMonster->isAlive()) {
                cout << "\nYour HP: " << player->getHealth() << " | Enemy HP: " << currentMonster->getHealth() << endl;
                cout << "1) Attack  2) Use Item  3) Change Equipment\nChoose an action: ";
                int action;
                cin >> action;
                switch (action) {
                    case 1:
                        player->attack(currentMonster);
                        break;
                    case 2:
                        player->getInventory()->listItems();
                        cout << "Enter item index: ";
                        int i;
                        cin >> i;
                        player->useItem(i);
                        break;
                case 3:
                        player->changeEquipment();
                        break;
                    default:
                        cout << "Invalid action!" << endl;
                }
                if (currentMonster->isAlive()) {
                    currentMonster->attack(player);
                }
                player->processStatusEffects();
            }
            if (player->isAlive()) {
                cout << "\nYou defeated the " << currentMonster->getName() << "!" << endl;
            }
        }
        Monster* generateMonster() {
            string name = "Monster Lvl" + to_string(level);
            int hp = 50 + 10 * level;
            int attack = 10 + 2 * level;
            int def = 5 + level;
            int spd = 5 + level / 2;
            int coins = 20 * level;
            float difficulty = 1.0 + (level * 0.1);

            return new Monster(name, level, hp, hp, attack, def, spd, coins, difficulty);
        }
        bool checkGameOver() {
            return !player->isAlive();
        }
         void gameLoop() {
            while (!gameOver) {
                shop->updateInventory(level);
                handleShop();
                currentMonster = generateMonster();
                battleLoop();
                gameOver = checkGameOver();

                if (!gameOver) {
                    player->addExperience(25* level);
                    player->addCoins(50 * level);
                    level++;
                    cout << "\nLevel passed! Next level" << level << "...\n" << endl;
                }
            }
            cout << "\nGame Over." << endl;
        }
        void start() {
            cout << "Welcome to the beginning of your journey!" << endl;
            string name;
            cout << "Enter your name: ";
            cin >> name;
            player = new Player(name, 1, 100, 100, 20, 10, 5, 0, 100);
            gameLoop();
        }
};

#endif