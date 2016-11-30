#include "FlameStrike.h"

FlameStrike::FlameStrike(int power, int cost, SpellTitle title) : Spell(power, cost, title) {}

FlameStrike::~FlameStrike() {}

void FlameStrike::action(Unit& target) {
    target.takeMagDamage(this->getPower());
}
