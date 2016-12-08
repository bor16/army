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
        Wizard(Class title=Class::WIZARD, int maxHp=static_cast<int>(Hp::WIZARD), int damage=static_cast<int>(Dmg::WIZARD), int maxMana=static_cast<int>(Mana::WIZARD));
        virtual ~Wizard();
        
        const int getMana() const;
        const int getMaxMana() const;
        const std::map<SpellTitle, Spell*>& openSpellbook() const;
        
        void reduceMana(int cost);
        void restoreMana(int points);
        
        Spell& findSpell(SpellTitle title) const;
        virtual void cast(SpellTitle title, Unit& target);
};

#endif //WIZARD_H
