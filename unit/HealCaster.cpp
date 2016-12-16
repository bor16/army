#include "HealCaster.h"
#include "../modifier/Damage.h"

HealCaster::HealCaster(UnitClass title, int maxHp, int damage, int maxMana) : Caster(title, maxHp, damage, maxMana) {}

HealCaster::~HealCaster() {}

void HealCaster::cast(Harm& spell, Unit& target) {
    Damage dmg;
    
    this->ensureIsAlive();
    
    dmg = spell.getCost();
    
    this->takeEnergyImpact(dmg);
    spell.action(target, 2);
    
    if ( target.getHealth() != 0 ) {
        target.counterAttack(*this, target);
    }
}

void HealCaster::cast(Restore& spell, Unit& target) {
    Damage dmg;
    
    this->ensureIsAlive();
    
    dmg = spell.getCost();
    
    this->takeEnergyImpact(dmg);
    spell.action(target, 1);
}
