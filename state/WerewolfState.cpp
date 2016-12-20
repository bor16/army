#include "WerewolfState.h"

WerewolfState::WerewolfState(UnitClass title, int maxHp, int damage) : State(title, new Health(maxHp), damage) {
    this->active = new State(title, new Health(maxHp), damage);
    this->alternative = new WolfState(title, new Health(maxHp*2), damage*2);
}

WerewolfState::~WerewolfState() {
    delete active;
    delete alternative;
}

const Health WerewolfState::getHealth() const {
    return active->getHealth();
}

void WerewolfState::shapeShift() {
    State* tmp = active;
    
    active = alternative;
    alternative = tmp;
}

void WerewolfState::takeImpact(Modifier& mod) {
    this->active->takeImpact(mod);
    this->alternative->takeImpact(mod);
}

void WerewolfState::takeMagDamage(Modifier& mod) {
    this->active->takeMagDamage(mod);
    this->alternative->takeMagDamage(mod);
}
