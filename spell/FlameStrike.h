#ifndef FLAMESTRIKE_H
#define FLAMESTRIKE_H

#include <iostream>
#include "Harm.h"

class FlameStrike: public Harm {
    public:
        FlameStrike(SpellTitle title=SpellTitle::FLAME_STRIKE, int power=(int)Power::FLAME_STRIKE, int cost=(int)Cost::FLAME_STRIKE);
        virtual ~FlameStrike();
        
        void action(Unit& target, int modifier);
};

#endif //FLAMESTRIKE_H
