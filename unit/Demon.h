#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "Soldier.h"

class Demon : public Soldier {
    public:
        Demon(UnitClass title=UnitClass::DEMON, int maxHp=(int)Hp::DEMON, int damage=(int)Dmg::DEMON);
        virtual ~Demon();
};

#endif //DEMON_H
