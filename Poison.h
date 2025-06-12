#ifndef POISON_H 
#define POISON_H
#include <string>
#include "StatusEffects.h"

using namespace std;

// Declaration of class Poison
// Inherits from class StatusEffect
class Poison : public StatusEffect{
    private:
    // Amount of damage posion does per turn
        int damagePerTurn;

    public:
        // Constructors
        Poison()
        : StatusEffect(), damagePerTurn() {}
        Poison(string name, int duration, int damagePerTurn);
        // Applies posion effect
        void applyEffect(Character* target){
            if (target != nullptr) {
                target->takeDamage(damagePerTurn);
            }
        }
        // Update remaining turn duration
        void update(){
            duration--;
        }
        // Checks to see if its expired
        bool isExpired(){
            return duration <= 0;
        }
};

#endif
