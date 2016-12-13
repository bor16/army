#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "Healer.h"

class Priest : public Healer {
    public:
        Priest(unitClass title=unitClass::PRIEST, int maxHp=(int)Hp::PRIEST, int damage=(int)Dmg::PRIEST, int maxMana=(int)Mana::PRIEST);
        virtual ~Priest();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //PRIEST_H
