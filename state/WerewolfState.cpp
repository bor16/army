#include "WerewolfState.h"

WerewolfState::WerewolfState(UnitClass title, int maxHp, int damage) : State(title, maxHp, damage) {
    this->active = new State(title, maxHp, damage);
    this->alternative = new WolfState(title, maxHp*2, damage*2);
}

WerewolfState::~WerewolfState() {
    delete active;
    delete alternative;
}

const int WerewolfState::getHp() const {
    return active->getHp();
}

void WerewolfState::shapeShift() {
    State* tmp = active;
    
    active = alternative;
    alternative = tmp;
}

void WerewolfState::takeDamage(int damage) {
    this->active->takeDamage(damage);
    this->alternative->takeDamage(damage);
}

void WerewolfState::takeMagDamage(int damage) {
    this->active->takeMagDamage(damage);
    this->alternative->takeMagDamage(damage);
}

void WerewolfState::restoreHp(int points) {
    this->active->restoreHp(points);
    this->alternative->restoreHp(points);
}
