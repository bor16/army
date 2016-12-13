#ifndef CASTER_STATE_H
#define CASTER_STATE_H

#include <iostream>
#include "State.h"

class CasterState: public State {
    protected:
        int mana;
        int maxMana;
        
        void calcMana(int points);
        
    public:
        CasterState(unitClass title, int maxHp, int damage, int maxMana);
        virtual ~CasterState();
        
        const int getMana() const;
        const int getMaxMana() const;
        
        virtual void reduceMana(int cost);
        virtual void restoreMana(int points);
};

#endif //CASTER_STATE_H
