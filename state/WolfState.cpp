#include "WolfState.h"

WolfState::WolfState(const std::string& name, const std::string& unitClass, int maxHp, int damage) : State(name, unitClass, maxHp, damage) {}

WolfState::~WolfState() {}

void WolfState::calcHp(double points) {
    points += this->hp;
    if ( points < 0 ) {
        points = 0;
    }
    if ( points > this->maxHp ) {
        points = this->maxHp;
    }
    this->hp = points;
}

void WolfState::takeDamage(int damage) {
    this->ensureIsAlive();
    this->calcHp(-(double)damage/2);
}

void WolfState::takeMagDamage(int damage) {
    this->ensureIsAlive();
    this->calcHp(-damage*2);
}
