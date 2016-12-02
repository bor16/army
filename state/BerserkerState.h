#ifndef BERSERKERSTATE_H
#define BERSERKERSTATE_H

#include <iostream>
#include "State.h"

class BerserkerState : public State {
    public:
        BerserkerState(const std::string& name, UnitClass title, int maxHp, int damage);
        virtual ~BerserkerState();
        
        virtual void takeMagDamage(int damage);
};

#endif //BERSERKERSTATE_H
