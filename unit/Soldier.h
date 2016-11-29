#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, const std::string& unitClass="Soldier", int maxHp=100, int damage=10);
        virtual ~Soldier();
        
        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);
};

#endif //SOLDIER_H
