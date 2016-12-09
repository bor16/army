#ifndef HARM_H
#define HARM_H

#include <iostream>
#include "Spell.h"

class Harm: public Spell {
    public:
        Harm(SpellTitle title=SpellTitle::HEAL, int power=static_cast<int>(Power::HEAL), int cost=static_cast<int>(Cost::HEAL));
        virtual ~Harm();
        
        virtual void action(Unit& target, int modifier) = 0;
};

#endif //HARM_H
