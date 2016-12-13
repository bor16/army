#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "State.h"

class BerserkerState : public State {
    public:
        BerserkerState(UnitClass title, int maxHp, int damage);
        virtual ~BerserkerState();
        
        void takeMagDamage(int damage);
};

#endif //BERSERKER_STATE_H
