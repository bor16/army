#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(Class title=Class::SOLDIER, int maxHp=(int)Hp::SOLDIER, int damage=(int)Dmg::SOLDIER);
        virtual ~Soldier();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
};

#endif //SOLDIER_H
