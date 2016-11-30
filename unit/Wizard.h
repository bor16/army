#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include "Soldier.h"
#include "../state/CasterState.h"
#include "../spell/Spell.h"

class Wizard : public Soldier {
    protected:
        CasterState* state;
    
    public:
        Wizard(const std::string& name, UnitClass title=WIZARD, int maxHp=50, int damage=3, int maxMana=100);
        virtual ~Wizard();
        
        const int getMana() const;
        const int getMaxMana() const;
        
        void reduceMana(int cost);
        void restoreMana(int points);
        
        void cast(Unit& target, Spell& spell);
};

#endif //WIZARD_H
