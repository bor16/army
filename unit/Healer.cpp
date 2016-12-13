#include "Healer.h"

Healer::Healer(unitClass title, int maxHp, int damage, int maxMana) : HealCaster(title, maxHp, damage, maxMana) {}

Healer::~Healer() {}

void Healer::cast(Harm& spell, Unit& target) {
    HealCaster::cast(spell, target);
}

void Healer::cast(Restore& spell, Unit& target) {
    HealCaster::cast(spell, target);
}
