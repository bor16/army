#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(UnitClass title=UnitClass::SOLDIER, int maxHp=(int)Hp::SOLDIER, int damage=(int)Dmg::SOLDIER);
        virtual ~Soldier();
};

#endif //SOLDIER_H
