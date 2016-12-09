#include "FlameStrike.h"

FlameStrike::FlameStrike(SpellTitle title, int power, int cost) : Spell(title, power, cost) {}

FlameStrike::~FlameStrike() {}

void FlameStrike::action(Unit& target) {
    target.takeDamage(this->getPower());
}
