#ifndef DEFENSIVE_H
#define DEFENSIVE_H

#include <iostream>
#include "Spell.h"

class Defensive : public Spell {
    public:
        Defensive(SpellTitle title, int power, int cost);
        virtual ~Defensive();
        
        virtual void assist(Unit& target) = 0;
};

#endif //DEFENSIVE_H
