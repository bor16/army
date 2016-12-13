#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Caster.h"

class Wizard : public Caster {
    public:
        Wizard(unitClass title=unitClass::WIZARD, int maxHp=(int)Hp::WIZARD, int damage=(int)Dmg::WIZARD, int maxMana=(int)Mana::WIZARD);
        virtual ~Wizard();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //WIZARD_H
