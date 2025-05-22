#ifndef STATUSEFFECTS_H
#define STATUSEFFECTS_H
#include <string>
#include "Character.h"

using namespace std;

class StatusEffect{
    protected:
        string name;
        int duration;
    
    public:
        StatusEffect()
        : name(), duration() {}
        StatusEffect()
        : name(name), duration(duration) {}

        string getName() const;
        int getDuration() const;
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