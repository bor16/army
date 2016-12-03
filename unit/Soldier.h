#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"
#include "../state/UnitClass.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, UnitClass title=UnitClass::SOLDIER, int maxHp=100, int damage=10);
        virtual ~Soldier();
        
        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);
};

#endif //SOLDIER_H
