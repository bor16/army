#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Soldier.h"
#include "../state/BerserkerState.h"

class Berserker : public Soldier {
    protected:
        BerserkerState* state;
    
    public:
        Berserker(const std::string& name, UnitClass title=UnitClass::BERSERKER, int maxHp=70, int damage=7);
        virtual ~Berserker();
};

#endif //BERSERKER_H
