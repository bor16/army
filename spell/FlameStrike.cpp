#include "FlameStrike.h"

FlameStrike::FlameStrike(SpellTitle title, int power, int cost) : Harm(title, power, cost) {}

FlameStrike::~FlameStrike() {}

void FlameStrike::action(Unit& target, int modifier) {
    Harm::action(target, modifier);
}
