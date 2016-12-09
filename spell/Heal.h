#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Restore.h"

class Heal: public Restore {
    public:
        Heal(SpellTitle title=SpellTitle::HEAL, int power=static_cast<int>(Power::HEAL), int cost=static_cast<int>(Cost::HEAL));
        virtual ~Heal();
        
        void action(Unit& target, int modifier);
};

#endif //HEAL_H
