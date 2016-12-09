#include "FlameStrike.h"

FlameStrike::FlameStrike(SpellTitle title, int power, int cost) : Offensive(title, power, cost) {}

FlameStrike::~FlameStrike() {}

void FlameStrike::action(Unit& target) {
    harm(target);
}

void FlameStrike::harm(Unit& target) {
    target.takeMagDamage(this->getPower());
}
