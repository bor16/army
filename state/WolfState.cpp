#include "WolfState.h"

WolfState::WolfState(UnitClass title, int maxHp, int damage) : State(title, maxHp, damage) {}

WolfState::~WolfState() {}

void WolfState::takeMagDamage(int damage) {
    this->calcHp(-damage*2);
}
