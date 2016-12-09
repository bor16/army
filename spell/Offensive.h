#ifndef OFFENSIVE_H
#define OFFENSIVE_H

#include <iostream>
#include "Spell.h"

class Offensive : public Spell {
    public:
        Offensive(SpellTitle title, int power, int cost);
        virtual ~Offensive();
        
        virtual void harm(Unit& target) = 0;
};

#endif //OFFENSIVE_H
