#ifndef COMBATCASTER_H
#define COMBATCASTER_H

#include <iostream>
#include "Caster.h"

class CombatCaster : public Caster {
    public:
        CombatCaster(Class title=Class::WIZARD, int maxHp=static_cast<int>(Hp::WIZARD), int damage=static_cast<int>(Dmg::WIZARD), int maxMana=static_cast<int>(Mana::WIZARD));
        virtual ~CombatCaster();
        
        virtual void cast(Harm& spell, Unit& target) = 0;
        virtual void cast(Restore& spell, Unit& target) = 0;
};

#endif //COMBATCASTER_H
