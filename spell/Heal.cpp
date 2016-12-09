#include "Heal.h"

Heal::Heal(SpellTitle title, int power, int cost) : Spell(title, power, cost) {}

Heal::~Heal() {}

void Heal::action(Unit& target) {
    target.restoreHp(this->getPower());
}
