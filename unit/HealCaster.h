#ifndef HEALCASTER_H
#define HEALCASTER_H

#include <iostream>
#include "Caster.h"

class HealCaster : public Caster {
    public:
        HealCaster(Class title=Class::WIZARD, int maxHp=(int)Hp::WIZARD, int damage=(int)Dmg::WIZARD, int maxMana=(int)Mana::WIZARD);
        virtual ~HealCaster();
        
        virtual void cast(Harm& spell, Unit& target) = 0;
        virtual void cast(Restore& spell, Unit& target) = 0;
};

#endif //HEALCASTER_H
