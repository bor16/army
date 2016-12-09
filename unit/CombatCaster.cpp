#include "CombatCaster.h"

CombatCaster::CombatCaster(Class title, int maxHp, int damage, int maxMana) : Caster(title, maxHp, damage, maxMana) {}

CombatCaster::~CombatCaster() {}

void CombatCaster::cast(Harm& spell, Unit& target) {
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 1);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}

void CombatCaster::cast(Restore& spell, Unit& target) {
    this->state->ensureIsAlive();
    
    this->reduceMana(spell.getCost());
    spell.action(target, 2);
}
