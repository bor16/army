#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

typedef enum {
    FLAME_STRIKE,
    HEAL
} SpellTitle;

class Spell {
    protected:
        int power;
        int cost;
        SpellTitle title;
        
    public:
        Spell(int power, int cost, SpellTitle title);
        virtual ~Spell();
        
        const int getPower() const;
        const int getCost() const;
        SpellTitle getTitle() const;
        
        virtual void action(Unit& target) = 0;
};

#endif //SPELL_H
