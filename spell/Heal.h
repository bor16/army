#ifndef HEAL_H
#define HEAL_H

#include <iostream>
#include "Spell.h"
#include "../interface/i_spell/IDefensive.h"

class Heal: public Spell, public IDefensive {
    public:
        Heal(SpellTitle title=SpellTitle::HEAL, int power=static_cast<int>(Power::HEAL), int cost=static_cast<int>(Cost::HEAL));
        virtual ~Heal();
        
        void action(Unit& target);
        void assist(Unit& target);
};

#endif //HEAL_H
