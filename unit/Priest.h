#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "Wizard.h"

class Priest : public Wizard {
    public:
        Priest(const std::string& name, UnitClass title=WIZARD, int maxHp=70, int damage=4, int maxMana=80);
        virtual ~Priest();
};

#endif //PRIEST_H
