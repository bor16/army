#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Spell.h"

class FlameStrike: public Spell {
    public:
        FlameStrike(int power=20, int cost=40, SpellTitle title=SpellTitle::FLAME_STRIKE);
        virtual ~FlameStrike();
        
        virtual void action(Unit& target);
};

#endif //FLAMESTRIKE_H
