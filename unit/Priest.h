#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "Wizard.h"

class Priest : public Wizard {
    public:
        Priest(Class title=Class::PRIEST, int maxHp=static_cast<int>(Hp::PRIEST), int damage=static_cast<int>(Dmg::PRIEST), int maxMana=static_cast<int>(Mana::PRIEST));
        virtual ~Priest();
};

#endif //PRIEST_H
