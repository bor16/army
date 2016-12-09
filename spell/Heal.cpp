#include "Heal.h"

Heal::Heal(SpellTitle title, int power, int cost) : Defensive(title, power, cost) {}

Heal::~Heal() {}

void Heal::action(Unit& target) {
    assist(target);
}

void Heal::assist(Unit& target) {
    target.restoreHp(this->getPower());
}
