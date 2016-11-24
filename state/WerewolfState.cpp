#include "WerewolfState.h"

WerewolfState::WerewolfState(const std::string& name, const std::string& unitClass, int maxHp, int damage, bool isWolf) : State(name, unitClass, maxHp, damage) {}

WerewolfState::~WerewolfState() {}

const bool WerewolfState::wolf() const {
    return this->isWolf;
}

void WerewolfState::boost(int modifier) {
    hp *= modifier;
    maxHp *= modifier;
    damage *= modifier;
}

void WerewolfState::shrink(int modifier) {
    hp /= modifier;
    maxHp /= modifier;
    damage /= modifier;
}
