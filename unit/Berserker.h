#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Soldier.h"
#include "../state/BerserkerState.h"

class Berserker : public Soldier {
    protected:
        BerserkerState* state;
    
    public:
        Berserker(unitClass title=unitClass::BERSERKER, int maxHp=(int)Hp::BERSERKER, int damage=(int)Dmg::BERSERKER);
        virtual ~Berserker();
        
        void takeMagDamage(int damage);
};

#endif //BERSERKER_H
