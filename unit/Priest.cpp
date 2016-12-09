#include "Priest.h"

Priest::Priest(Class title, int maxHp, int damage, int maxMana) : Healer(title, maxHp, damage, maxMana) {}

Priest::~Priest() {}

void Priest::cast(Harm& spell, Unit& target) {
    HealCaster::cast(spell, target);
}

void Priest::cast(Restore& spell, Unit& target) {
    HealCaster::cast(spell, target);
}
