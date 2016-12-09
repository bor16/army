#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"
#include "SpellProperties.h"

class Spell {
    protected:
        int power;
        int cost;
        SpellTitle title;
        
    public:
        Spell(SpellTitle title, int power, int cost);
        virtual ~Spell();
        
        const int getPower() const;
        const int getCost() const;
        SpellTitle getTitle() const;
        
        virtual void action(Unit& target, int modifier) = 0;
};

#endif //SPELL_H
