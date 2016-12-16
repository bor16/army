#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "StateProperties.h"
#include "../exception/Exception.h"
#include "../field/Health.h"

class State {
    protected:
        UnitClass title;
        Health health;
        int damage;
        
    public:
        State(UnitClass title, Health health, int damage);
        virtual ~State();
        
        UnitClass getTitle() const;
        const Health getHealth() const;
        const int getDamage() const;
        
        virtual void takeImpact(Modifier& mod);
        virtual void takeMagDamage(Modifier& mod);
};

#endif //STATE_H
