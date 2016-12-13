#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Soldier.h"
#include "../action/RogueAction.h"

class Rogue : public Soldier {
    protected:
        RogueAction* action;
    
    public:
        Rogue(UnitClass title=UnitClass::ROGUE, int maxHp=(int)Hp::ROGUE, int damage=(int)Dmg::ROGUE);
        virtual ~Rogue();
        
        void attack(Unit& target, Unit& attacker);
};

#endif //ROGUE_H
