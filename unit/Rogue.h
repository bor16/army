#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "Soldier.h"

class Rogue : public Soldier {
    public:
        Rogue(Class title=Class::ROGUE, int maxHp=static_cast<int>(Hp::ROGUE), int damage=static_cast<int>(Dmg::ROGUE));
        virtual ~Rogue();
        
        void attack(Unit& target);
};

#endif //ROGUE_H
