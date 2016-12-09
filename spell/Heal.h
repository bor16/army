#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Defensive.h"

class Heal: public Defensive {
    public:
        Heal(SpellTitle title=SpellTitle::HEAL, int power=static_cast<int>(Power::HEAL), int cost=static_cast<int>(Cost::HEAL));
        virtual ~Heal();
        
        void action(Unit& target);
        void assist(Unit& target);
};

#endif //HEAL_H
