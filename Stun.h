#ifndef STUN_H 
#define STUN_H
#include <string>
#include "StatusEffects.h"
#include "Character.h"

using namespace std;

// Declaration of class Stun
// Inherits from class StatusEffects
class Stun : public StatusEffect{
    public:
        // Constructors
        Stun()
        : StatusEffect() {}
        Stun(string name, int duration);
        // Applies stun effect
        void applyEffect(Character* target);
        // Updates remaining turn duration
        void update() {
            duration--;
        }
        // Checks to see if its expired
        bool isExpired() {
            return duration <= 0;
        }
};

#endif
