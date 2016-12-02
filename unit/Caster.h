#ifndef CASTER_H
#define CASTER_H

#include <iostream>
#include <map>
#include "Soldier.h"
#include "../state/CasterState.h"
#include "../spell/Spell.h"
#include "../spell/FlameStrike.h"
#include "../spell/Heal.h"

class Caster : public Soldier {
    protected:
        CasterState* state;
        std::map<SpellTitle, Spell*>* spellbook;
    
    public:
        Caster(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana);
        virtual ~Caster();
        
        const int getMana() const;
        const int getMaxMana() const;
        const std::map<SpellTitle, Spell*>& openSpellbook() const;
        
        void reduceMana(int cost);
        void restoreMana(int points);
        
        Spell& findSpell(SpellTitle title) const;
        virtual void cast(SpellTitle title, Unit& target) = 0;
};

#endif //CASTER_H
