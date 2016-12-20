#include "WerewolfState.h"

WerewolfState::WerewolfState(UnitClass title, int maxHp, int damage) : State(title, new Health(maxHp), damage) {
    this->active = std::unique_ptr<State>(new State(title, new Health(maxHp), damage));
    this->alternative = std::unique_ptr<State>(new WolfState(title, new Health(maxHp*2), damage*2));
}

WerewolfState::~WerewolfState() {}

const Health WerewolfState::getHealth() const {
    return active->getHealth();
}

void WerewolfState::shapeShift() {
    std::unique_ptr<State> tmp(nullptr);
    
    swap(tmp, active);
    swap(active, alternative);
    swap(alternative, tmp);
    
    // tmp = std::move(active);
    // active = std::move(alternative);
    // alternative = std::move(tmp);
}

void WerewolfState::takeImpact(Modifier& mod) {
    this->active->takeImpact(mod);
    this->alternative->takeImpact(mod);
}

void WerewolfState::takeMagDamage(Modifier& mod) {
    this->active->takeMagDamage(mod);
    this->alternative->takeMagDamage(mod);
}
