#ifndef WOLF_STATE_H
#define WOLF_STATE_H

#include <iostream>
#include "State.h"
#include "../modifier/Modifier.h"
#include "../modifier/MagDamage.h"

class WolfState : public State {
    public:
        WolfState(UnitClass title, Health* health, int damage);
        virtual ~WolfState();
        
        void takeImpact(Modifier& mod);
        void takeImpact(MagDamage& mod);
        void takeMagDamage(Modifier& mod);
};

#endif //WOLF_STATE_H
