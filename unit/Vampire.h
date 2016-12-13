#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Soldier.h"
#include "../action/VampireAction.h"

class Vampire : public Soldier {
    protected:
        VampireAction* action;
        
    public:
        Vampire(unitClass title=unitClass::VAMPIRE, int maxHp=(int)Hp::VAMPIRE, int damage=(int)Dmg::VAMPIRE);
        virtual ~Vampire();
        
        void attack(Unit& target, Unit& attacker);
        void counterAttack(Unit& target, Unit& attacker);
};

#endif //VAMPIRE_H
