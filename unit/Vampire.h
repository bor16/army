#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Soldier.h"

class Vampire : public Soldier {
    public:
        Vampire(const std::string& name, UnitClass title=UnitClass::VAMPIRE, int maxHp=40, int damage=6);
        virtual ~Vampire();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
};

#endif //VAMPIRE_H
