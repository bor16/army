#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, const std::string& unitClass="soldier", int maxHp=100, int physDmg=10);
        virtual ~Soldier();
        
        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);
        virtual void takeDamage(int physDmg, int magDmg);
        virtual void restoreHp(int physPts, int magPts);
};

#endif //SOLDIER_H
