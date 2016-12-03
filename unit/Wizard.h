#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Caster.h"

class Wizard : public Caster {
    public:
        Wizard(const std::string& name, UnitClass title=UnitClass::WIZARD, int maxHp=50, int damage=3, int maxMana=100);
        virtual ~Wizard();
        
        void cast(SpellTitle title, Unit& target);
};

#endif //WIZARD_H
