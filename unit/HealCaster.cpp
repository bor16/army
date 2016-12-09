#include "HealCaster.h"

HealCaster::HealCaster(Class title, int maxHp, int damage, int maxMana) : Caster(title, maxHp, damage, maxMana) {}

HealCaster::~HealCaster() {}

void HealCaster::cast(Harm& spell, Unit& target) {
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 2);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}

void HealCaster::cast(Restore& spell, Unit& target) {
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 1);
}
