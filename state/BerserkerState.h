#ifndef BERSERKERSTATE_H
#define BERSERKERSTATE_H

#include <iostream>
#include "State.h"

class BerserkerState : public State {
    public:
        BerserkerState(Class title, int maxHp, int damage);
        virtual ~BerserkerState();
        
        void takeMagDamage(int damage);
};

#endif //BERSERKERSTATE_H
