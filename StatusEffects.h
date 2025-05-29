#ifndef STATUSEFFECTS_H
#define STATUSEFFECTS_H
#include <string>
#include "Character.h"

using namespace std;

class Character;

class StatusEffect{
    protected:
        string name;
        int duration;
    
    public:
        StatusEffect()
        : name(), duration() {}
        StatusEffect(string name, int duration)
        : name(name), duration(duration) {}

        string getName();
        int getDuration();
        void setDuration(int d);

        virtual void applyEffect(Character* target);
        virtual void update() {
            if (duration > 0) {
                duration = - 1;
            }
        }
        virtual bool isExpired() {
            return duration <= 0;
        }
};
#endif
