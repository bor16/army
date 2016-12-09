#ifndef RESTORE_H
#define RESTORE_H

#include <iostream>
#include "Spell.h"

class Restore: public Spell {
    public:
        Restore(SpellTitle title=SpellTitle::HEAL, int power=(int)Power::HEAL, int cost=(int)Cost::HEAL);
        virtual ~Restore();
        
        virtual void action(Unit& target, int modifier) = 0;
};

#endif //RESTORE_H
