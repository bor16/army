#include "Heal.h"

Heal::Heal(int power, int cost, SpellTitle title) : Spell(power, cost, title) {}

Heal::~Heal() {}

void Heal::action(Unit& target) {
    target.restoreHp(this->getPower());
}
