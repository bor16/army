#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Soldier.h"
#include "../state/BerserkerState.h"

class Berserker : public Soldier {
    protected:
        BerserkerState* state;
    
    public:
        Berserker(Class title=Class::BERSERKER, int maxHp=static_cast<int>(Hp::BERSERKER), int damage=static_cast<int>(Dmg::BERSERKER));
        virtual ~Berserker();
};

#endif //BERSERKER_H
