#ifndef BERSERKER_H
#define BERSERKER_H

#include <iostream>
#include "Soldier.h"
#include "../state/BerserkerState.h"
#include "../modifier/MagDamage.h"

class Berserker : public Soldier {
    protected:
        std::unique_ptr<BerserkerState> state;
    
    public:
        Berserker(UnitClass title=UnitClass::BERSERKER, int maxHp=(int)Hp::BERSERKER, int damage=(int)Dmg::BERSERKER);
        virtual ~Berserker();
        
        void takeImpact(Modifier& mod);
        void takeImpact(MagDamage& mod);
        void takeMagDamage(Modifier& mod);
};

#endif //BERSERKER_H
