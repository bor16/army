#ifndef CASTER_STATE_H
#define CASTER_STATE_H

#include <iostream>
#include "State.h"
#include "../field/Energy.h"

class CasterState: public State {
    protected:
        Energy energy;
        
    public:
        CasterState(UnitClass title, Health health, int damage, Energy energy);
        virtual ~CasterState();
        
        const Energy getEnergy() const;
        
        virtual void takeEnergyImpact(Modifier& mod);
};

#endif //CASTER_STATE_H
