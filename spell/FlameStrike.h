#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Spell.h"
#include "../interface/i_spell/IOffensive.h"

class FlameStrike: public Spell, public IOffensive {
    public:
        FlameStrike(SpellTitle title=SpellTitle::FLAME_STRIKE, int power=static_cast<int>(Power::FLAME_STRIKE), int cost=static_cast<int>(Cost::FLAME_STRIKE));
        virtual ~FlameStrike();
        
        void action(Unit& target);
        void harm(Unit& target);
};

#endif //FLAMESTRIKE_H
