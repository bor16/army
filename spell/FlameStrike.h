#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Offensive.h"

class FlameStrike: public Offensive {
    public:
        FlameStrike(SpellTitle title=SpellTitle::FLAME_STRIKE, int power=static_cast<int>(Power::FLAME_STRIKE), int cost=static_cast<int>(Cost::FLAME_STRIKE));
        virtual ~FlameStrike();
        
        void action(Unit& target);
        void harm(Unit& target);
};

#endif //FLAMESTRIKE_H
