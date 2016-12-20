#include "Harm.h"
#include "../modifier/Damage.h"

Harm::Harm(SpellTitle title, int power, int cost) : Spell(title, power, cost) {}

Harm::~Harm() {}

void Harm::action(Unit& target, int modifier) {
    Damage dmg;
    
    dmg = this->getPower()/modifier;
    
    target.takeMagDamage(dmg);
}
