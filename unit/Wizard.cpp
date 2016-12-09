#include "Wizard.h"

Wizard::Wizard(Class title, int maxHp, int damage, int maxMana) : CombatCaster(title, maxHp, damage, maxMana) {}

Wizard::~Wizard() {}

void Wizard::cast(Harm& spell, Unit& target) {
    CombatCaster::cast(spell, target);
}

void Wizard::cast(Restore& spell, Unit& target) {
    CombatCaster::cast(spell, target);
}
