#include "Wizard.h"

Wizard::Wizard(unitClass title, int maxHp, int damage, int maxMana) : Caster(title, maxHp, damage, maxMana) {}

Wizard::~Wizard() {}

void Wizard::cast(Harm& spell, Unit& target) {
    Caster::cast(spell, target);
}

void Wizard::cast(Restore& spell, Unit& target) {
    Caster::cast(spell, target);
}
