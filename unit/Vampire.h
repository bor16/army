#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Soldier.h"

class Vampire : public Soldier {
    public:
        Vampire(const std::string& name, UnitClass title=VAMPIRE, int maxHp=40, int damage=6);
        virtual ~Vampire();
        
        void attack(Unit& enemy);
        void counterAttack(Unit& enemy);
};

#endif //VAMPIRE_H
