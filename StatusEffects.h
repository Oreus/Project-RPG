#ifndef STATUSEFFECTS_H
#define STATUSEFFECTS_H
#include <string>
#include "Character.h"

using namespace std;

class Character;

// Declaration of class StatusEffect
// This class is an abstract  class that is a base class 
// for Posion and stun
class StatusEffect{
    protected:
        // Status Effect attributes
        string name;
        int duration;
    
    public:
        // Constructors
        StatusEffect()
        : name(), duration() {}
        StatusEffect(string name, int duration)
        : name(name), duration(duration) {}
        // Getters
        string getName() {
            return name;
        }
        int getDuration() {
            return duration;
        }
        //Setter
        void setDuration(int d) {
            duration = d;
        }
        //Virtual method for the application of an effect
        // is meant to be overriden by different effects
        virtual void applyEffect(Character* target) = 0;
        //Virtual method for the updating of an effect duration
        // is meant to be overriden by different effects
        virtual void update() {
            if (duration > 0) {
                duration--;
            }
        }
        //Virtual method for the checking of an effect duration
         // is meant to be overriden by different effects
        virtual bool isExpired() {
            return duration <= 0;
        }
};

#endif
