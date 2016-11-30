#ifndef CASTERSTATE_H
#define CASTERSTATE_H

#include <iostream>
#include "State.h"

class CasterState: public State {
    protected:
        int mana;
        int maxMana;
        
        void calcMana(int points);
        
    public:
        CasterState(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana);
        virtual ~CasterState();
        
        const int getMana() const;
        const int getMaxMana() const;
        
        void reduceMana(int cost);
        void restoreMana(int points);
};

#endif //CASTERSTATE_H
