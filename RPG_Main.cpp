#include "Character.h"
#include "Monster.h"
#include <iostream>

using namespace std;

int main() {
    Monster Dragon("Dragon", 13, 30, 28, 38, 13, 25, 13, 5.2);
    cout << "Monster created!" << endl;
    cout << "Name: " << Dragon.getName() << endl;
    cout << "Level: " << Dragon.getLevel() << endl;
    cout << "Health: " << Dragon.getHealth() << endl;
    return 0;
};