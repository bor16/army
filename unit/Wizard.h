#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <map>
#include "Soldier.h"
#include "../state/CasterState.h"
#include "../spell/Spell.h"
#include "../spell/FlameStrike.h"
#include "../spell/Heal.h"

class Wizard : public Soldier {
    protected:
        CasterState* state;
        std::map<SpellTitle, Spell*>* spellbook;
    
    public:
        Wizard(const std::string& name, UnitClass title=WIZARD, int maxHp=50, int damage=3, int maxMana=100);
        virtual ~Wizard();
        
        const int getMana() const;
        const int getMaxMana() const;
        const std::map<SpellTitle, Spell*>& openSpellbook() const;
        
        void reduceMana(int cost);
        void restoreMana(int points);
        
        Spell& findSpell(SpellTitle title) const;
        void cast(SpellTitle title, Unit& target);
};

#endif //WIZARD_H
