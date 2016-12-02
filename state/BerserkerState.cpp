#include "BerserkerState.h"

BerserkerState::BerserkerState(const std::string& name, UnitClass title, int maxHp, int damage) : State(name, title, maxHp, damage) {}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(int damage) {
    return;
}
