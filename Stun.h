#ifndef STUN_H 
#define POISOSTUN_HN_H
#include <string>
#include "StatusEffects.h"

using namespace std;

class Stun : public StatusEffect{
    public:
        Stun()
        : StatusEffect() {}
        Stun(string name, int duration);

        void applyEffect();
        void update();
        bool isExpired();
};

#endif