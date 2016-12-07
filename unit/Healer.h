#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "Wizard.h"

class Healer : public Wizard {
    public:
        Healer(Class title=Class::HEALER, int maxHp=static_cast<int>(Hp::HEALER), int damage=static_cast<int>(Dmg::HEALER), int maxMana=static_cast<int>(Mana::HEALER));
        virtual ~Healer();
};

#endif //HEALER_H
