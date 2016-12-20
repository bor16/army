#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Soldier.h"
#include "../state/WerewolfState.h"

class Werewolf : public Soldier {
    protected:
        std::unique_ptr<WerewolfState> state;
        
    public:
        Werewolf(UnitClass title=UnitClass::WEREWOLF, int maxHp=(int)Hp::WEREWOLF, int damage=(int)Dmg::WEREWOLF);
        virtual ~Werewolf();
        
        const Health getHealth() const;
        
        void shapeShift();
        
        void takeImpact(Modifier& mod);
        void takeMagDamage(Modifier& mod);
};

#endif //WEREWOLF_H
