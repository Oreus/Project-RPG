#ifndef GAME_H
#define GAME_H
#include <cstdlib>
#include "Player.h"
#include "Monster.h"
#include "Shop.h"

using namespace std;

// Declaration of class Game
// Handles the main game flow logic
class Game {
    private:
        // Instance variables
        Player* player;
        Monster* currentMonster;
        Shop* shop;
        int level;
        bool gameOver;
        // A method for checking that user inputs match the options given
        // Made in private to prevent any unwanted errors of calling in public
        int promptForInt(const string& prompt) {
            while (true) {
                cout << prompt;
                string input;
                getline(cin, input);
                if (input == "q" or input == "Q") {
                    exitGame();
                }
                try {
                    int value = stoi(input);
                    return value;
                }
                catch (const exception& e) {
                    cout << "Invalid input, please enter a valid number or 'q' to exit." << endl;
                }
            }
        }
        // Method for exiting the game without having to die
        void exitGame() {
            cout << "\nExiting game" << endl;
            exit(0);
        }

    public:
        // Constructors, and makes a new shop on new game start
        Game() : player(nullptr), currentMonster(nullptr),
        shop(new Shop()), level(1), gameOver(false) {}


        // Handles all of the "surface level" shop mechanics: buying, displaying, change equipment
        void handleShop() {
            cout << "\n--- Shop ---" << endl;
            // Display player coins
            cout << "You currenly have " << player->getCoins() << " coins." << endl;
            shop->displayItem();
            cout << "Enter the number of the item to buy (-1 to exit): ";
            int choice;
            while (true) {
                cin >> choice;
                if (choice == -1) break;
                if (!shop->buyItem(choice, player)) {
                    cout << "Invalid selection." << endl;
                }
                // Display updated coin count
                cout << "You now have " << player->getCoins() << " coins." << endl;
                cout << "Buy another item? (-1 to exit): ";
            }
            cout << "\nWould you like to change equipment? (1 = yes, 0 = no): ";
            int change;
            cin >> change;
            if (change == 1) {
                player->changeEquipment();
            }
        }
        // Handles the encounters between the player and monster
        void battleLoop() {
            cout << "\nA " << currentMonster->getName() << " appeared!" << endl;
            while (player->isAlive() && currentMonster->isAlive()) {
                cout << "\nYour HP: " << player->getHealth() 
                << " | Enemy HP: " << currentMonster->getHealth() << endl;
                int action = 
                promptForInt("1) Attack  2) Use Item  3) Change Equipment\nChoose an action: ");
                switch (action) {
                    // Attack
                    case 1:
                        player->attack(currentMonster);
                        break;
                    // Use item
                    case 2:
                        player->getInventory()->listItems(); {
                        int itemIndex = promptForInt("Enter item index: ");
                        player->useItem(itemIndex);
                        }
                        break;
                    // Change equipment
                case 3:
                        player->changeEquipment();
                        break;
                    default:
                        cout << "Invalid action!" << endl;
                }
                // IF monster is alive, attack player
                if (currentMonster->isAlive()) {
                    currentMonster->attack(player);
                }
                player->processStatusEffects();
            }
            if (player->isAlive()) {
                cout << "\nYou defeated the " << currentMonster->getName() << "!" << endl;
            }
        }
        // Generates a new monster with scaled level based on 
        Monster* generateMonster() {
            string name = "Monster Lvl" + to_string(level);
            // Scales the level of the monster
            int hp = 50 + 10 * level;
            int attack = 10 + 2 * level;
            int def = 5 + level;
            int spd = 5 + level / 2;
            int coins = 20 * level;
            float difficulty = 1.0 + (level * 0.1);

            return new Monster(name, level, hp, hp, attack, def, spd, coins, difficulty);
        }
        // Check to see if the player has died in order to end the game
        bool checkGameOver() {
            return !player->isAlive();
        }
        // Controls the flow of the overall game such by combining the previous functions
         void gameLoop() {
            while (!gameOver) {
                shop->updateInventory(level);
                handleShop();
                currentMonster = generateMonster();
                battleLoop();
                gameOver = checkGameOver();
                // Rewards the player for beating the current monster
                if (!gameOver) {
                    player->addExperience(25* level);
                    player->addCoins(50 * level);
                    level++;
                    cout << "\nLevel passed! Next level" << level << "...\n" << endl;
                }
            }
            cout << "\nGame Over." << endl;
        }
        // The function that starts the main game loop
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
