#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"

class Heal: public Spell {
    public:
        Heal(SpellTitle title=SpellTitle::HEAL, int power=static_cast<int>(Power::HEAL), int cost=static_cast<int>(Cost::HEAL));
        virtual ~Heal();
        
        void action(Unit& target);
};

#endif //HEAL_H
