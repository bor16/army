#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "State.h"

class BerserkerState : public State {
    public:
        BerserkerState(UnitClass title, Health health, int damage);
        virtual ~BerserkerState();
        
        void takeMagDamage(Modifier& mod);
};

#endif //BERSERKER_STATE_H
