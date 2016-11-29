#include "BerserkerState.h"

BerserkerState::BerserkerState(const std::string& name, const std::string& unitClass, int maxHp, int damage) : State(name, unitClass, maxHp, damage) {}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(int damage) {
    return;
}
