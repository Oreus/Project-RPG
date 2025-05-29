#ifndef POISON_H 
#define POISON_H
#include <string>
#include "StatusEffects.h"

using namespace std;

class Poison : public StatusEffect{
    private:
        int damagePerTurn;

    public:
        Poison()
        : StatusEffect(), damagePerTurn() {}
        Poison(string name, int duration, int damagePerTurn);

        void applyEffect(Character* target){
            if (target != nullptr) {
                target->takeDamage(damagePerTurn);
            }
        }
        void update(){
            duration--;
        }
        bool isExpired(){
            return duration <= 0;
        }
};
#endif
