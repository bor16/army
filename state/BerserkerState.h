#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "State.h"
#include "../field/BerserkerHealth.h"

class BerserkerState : public State {
    protected:
        std::unique_ptr<BerserkerHealth> health;
    
    public:
        BerserkerState(UnitClass title, int maxHp, int damage);
        virtual ~BerserkerState();
        
        void takeImpact(Modifier& mod);
        void takeImpact(MagDamage& mod);
        void takeMagDamage(Modifier& mod);
};

#endif //BERSERKER_STATE_H
