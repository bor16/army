#ifndef WEREWOLF_STATE_H
#define WEREWOLF_STATE_H

#include <iostream>
#include "State.h"
#include "WolfState.h"

class WerewolfState : public State {
    protected:
        State* active;
        State* alternative;
        
    public:
        WerewolfState(UnitClass title, int maxHp, int damage);
        virtual ~WerewolfState();
        
        const int getHp() const;
        
        void shapeShift();
        
        void takeDamage(int damage);
        void takeMagDamage(int damage);
        void restoreHp(int points);
};

#endif //WEREWOLF_STATE_H
