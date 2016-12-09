#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "Healer.h"

class Priest : public Healer {
    public:
        Priest(Class title=Class::PRIEST, int maxHp=static_cast<int>(Hp::PRIEST), int damage=static_cast<int>(Dmg::PRIEST), int maxMana=static_cast<int>(Mana::PRIEST));
        virtual ~Priest();
        
        void cast(Harm& spell, Unit& target);
        void cast(Restore& spell, Unit& target);
};

#endif //PRIEST_H
