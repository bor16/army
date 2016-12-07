#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include "Soldier.h"

class Vampire : public Soldier {
    public:
        Vampire(Class title=Class::VAMPIRE, int maxHp=static_cast<int>(Hp::VAMPIRE), int damage=static_cast<int>(Dmg::VAMPIRE));
        virtual ~Vampire();
        
        void attack(Unit& target);
        void counterAttack(Unit& target);
};

#endif //VAMPIRE_H
