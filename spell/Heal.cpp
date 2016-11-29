#include "Heal.h"

Heal::Heal(int power, int cost, const std::string title) : Spell(power, cost, title) {}

Heal::~Heal() {}

void Heal::action(Unit& target) {
    target.restoreHp(this->getPower());
}
