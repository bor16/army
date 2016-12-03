#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "Wizard.h"

class Healer : public Wizard {
    public:
        Healer(const std::string& name, UnitClass title=UnitClass::WIZARD, int maxHp=60, int damage=2, int maxMana=100);
        virtual ~Healer();
};

#endif //HEALER_H
