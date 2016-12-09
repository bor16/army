#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "HealCaster.h"

class Healer : public HealCaster {
    public:
        Healer(Class title=Class::HEALER, int maxHp=static_cast<int>(Hp::HEALER), int damage=static_cast<int>(Dmg::HEALER), int maxMana=static_cast<int>(Mana::HEALER));
        virtual ~Healer();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //HEALER_H
