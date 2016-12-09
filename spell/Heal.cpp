#include "Heal.h"

Heal::Heal(SpellTitle title, int power, int cost) : Restore(title, power, cost) {}

Heal::~Heal() {}

void Heal::action(Unit& target, int modifier) {
    Restore::action(target, modifier);
}
