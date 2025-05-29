#ifndef STUN_H 
#define POISOSTUN_HN_H
#include <string>
#include "StatusEffects.h"
#include "Character.h"

using namespace std;

class Stun : public StatusEffect{
    public:
        Stun()
        : StatusEffect() {}
        Stun(string name, int duration);

        void applyEffect(Character* target);
        void update() {
            duration--;
        }
        bool isExpired() {
            return duration <= 0;
        }
};
#endif
