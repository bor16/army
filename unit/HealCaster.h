#ifndef HEAL_CASTER_H
#define HEAL_CASTER_H

#include <iostream>
#include "Caster.h"

class HealCaster : public Caster {
    public:
        HealCaster(unitClass title, int maxHp, int damage, int maxMana);
        virtual ~HealCaster();
        
        virtual void cast(Harm& spell, Unit& target) = 0;
        virtual void cast(Restore& spell, Unit& target) = 0;
};

#endif //HEAL_CASTER_H
