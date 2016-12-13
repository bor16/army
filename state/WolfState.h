#ifndef WOLF_STATE_H
#define WOLF_STATE_H

#include <iostream>
#include "State.h"

class WolfState : public State {
    public:
        WolfState(unitClass title, int maxHp, int damage);
        virtual ~WolfState();
        
        void takeMagDamage(int damage);
};

#endif //WOLF_STATE_H
