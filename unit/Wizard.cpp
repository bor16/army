#include "Wizard.h"

Wizard::Wizard(Class title, int maxHp, int damage, int maxMana) : Caster(title, maxHp, damage, maxMana) {}

Wizard::~Wizard() {}

void Wizard::cast(SpellTitle title, Unit& target) {
    Caster::cast(title, target);
}
