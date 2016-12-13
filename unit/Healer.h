#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "HealCaster.h"

class Healer : public HealCaster {
    public:
        Healer(UnitClass title=UnitClass::HEALER, int maxHp=(int)Hp::HEALER, int damage=(int)Dmg::HEALER, int maxMana=(int)Mana::HEALER);
        virtual ~Healer();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //HEALER_H
