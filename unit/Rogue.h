#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Soldier.h"

class Rogue : public Soldier {
    public:
        Rogue(const std::string& name, UnitClass title=UnitClass::ROGUE, int maxHp=60, int damage=8);
        virtual ~Rogue();
        
        void attack(Unit& enemy);
};

#endif //ROGUE_H
