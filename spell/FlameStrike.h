#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Spell.h"

class FlameStrike: public Spell {
    public:
        FlameStrike(SpellTitle title=SpellTitle::FLAME_STRIKE, int power=static_cast<int>(Power::FLAME_STRIKE), int cost=static_cast<int>(Cost::FLAME_STRIKE));
        virtual ~FlameStrike();
        
        void action(Unit& target);
};

#endif //FLAMESTRIKE_H
