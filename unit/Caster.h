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
        Caster(UnitClass title, int maxHp, int damage, int maxMana);
        virtual ~Caster();
        
        const Energy& getEnergy() const;
        const std::map<SpellTitle, Spell*>& openSpellbook() const;
        
        virtual void takeEnergyImpact(Modifier& mod);
        
        Spell& findSpell(SpellTitle title) const;
        virtual void cast(Harm& spell, Unit& target) = 0;
        virtual void cast(Restore& spell, Unit& target) = 0;
};

#endif //CASTER_H
