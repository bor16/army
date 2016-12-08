#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Caster.h"

class Wizard : public Caster {
    public:
        Wizard(Class title=Class::WIZARD, int maxHp=static_cast<int>(Hp::WIZARD), int damage=static_cast<int>(Dmg::WIZARD), int maxMana=static_cast<int>(Mana::WIZARD));
        virtual ~Wizard();
        
        void cast(SpellTitle title, Unit& target);
};
#endif //WIZARD_H
