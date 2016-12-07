#include "BerserkerState.h"

BerserkerState::BerserkerState(Class title, int maxHp, int damage) : State(title, maxHp, damage) {}

BerserkerState::~BerserkerState() {}

void BerserkerState::takeMagDamage(int damage) {
    return;
}
