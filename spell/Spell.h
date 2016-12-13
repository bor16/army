#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"
#include "SpellProperties.h"

class Spell {
    protected:
        SpellTitle title;
        int power;
        int cost;
        
    public:
        Spell(SpellTitle title, int power, int cost);
        virtual ~Spell();
        
        SpellTitle getTitle() const;
        const int getPower() const;
        const int getCost() const;
        
        virtual void action(Unit& target, int modifier) = 0;
};

#endif //SPELL_H
