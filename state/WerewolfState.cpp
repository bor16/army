#include "WerewolfState.h"

WerewolfState::WerewolfState(int maxHp, int physDmg) : State(maxHp, physDmg), isWolf(false) {}

WerewolfState::~WerewolfState() {}

const bool WerewolfState::wolf() const {
    return this->isWolf;
}

void WerewolfState::boost(int modifier) {
    hp *= modifier;
    maxHp *= modifier;
    physDmg *= modifier;
}

void WerewolfState::shrink(int modifier) {
    hp /= modifier;
    maxHp /= modifier;
    physDmg /= modifier;
}
