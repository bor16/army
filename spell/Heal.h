#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"

class Heal: public Spell {
    public:
        Heal(int power=20, int cost=40, SpellTitle title=HEAL);
        virtual ~Heal();
        
        virtual void action(Unit& target);
};

#endif //HEAL_H
