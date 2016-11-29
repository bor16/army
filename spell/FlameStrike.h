#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Spell.h"

class FlameStrike: public Spell {
    public:
        FlameStrike(int power=20, int cost=40, const std::string title="Flame Strike");
        virtual ~FlameStrike();
        
        virtual void action(Unit& target);
};

#endif //FLAMESTRIKE_H
