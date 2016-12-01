#include "Wizard.h"

Wizard::Wizard(const std::string& name, UnitClass title, int maxHp, int damage, int maxMana) : Caster(name, title, maxHp, damage, maxMana) {}

Wizard::~Wizard() {}

void Wizard::cast(SpellTitle title, Unit& target) {
    Spell& spell = findSpell(title);
    
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}
