#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "CombatCaster.h"

class Wizard : public CombatCaster {
    public:
        Wizard(Class title=Class::WIZARD, int maxHp=static_cast<int>(Hp::WIZARD), int damage=static_cast<int>(Dmg::WIZARD), int maxMana=static_cast<int>(Mana::WIZARD));
        virtual ~Wizard();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //WIZARD_H
