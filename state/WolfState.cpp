#include "WolfState.h"

WolfState::WolfState(Class title, int maxHp, int damage) : State(title, maxHp, damage) {}

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
    this->calcHp(-(double)damage/2);
}

void WolfState::takeMagDamage(int damage) {
    this->calcHp(-damage);
}
