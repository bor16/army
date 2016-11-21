#include "State.h"

State::State(int maxHp, int damage) : hp(maxHp), maxHp(maxHp), damage(damage) {}

State::~State() {}

void State::calcHp(int points) {
    points += this->hp;
    if ( points < 0 ) {
        points = 0;
    }
    if ( points > this->maxHp ) {
        points = this->maxHp;
    }
    this->hp = points;
}

const int State::getHp() const {
    return this->hp;
}
const int State::getMaxHp() const {
    return this->maxHp;
}
const int State::getDamage() const {
    return this->damage;
}

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        // throw DeadUnitException("ERROR: unit is dead");
    }
}

void State::takeDamage(int damage) {
    ensureIsAlive();
    this->calcHp(-damage);
}

void State::restoreHp(int points) {
    ensureIsAlive();
    this->calcHp(points);
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "hp(" << state.getHp() << "/" << state.getMaxHp() << "), ";
    out << "damage(" << state.getDamage() << ")";
    
    return out;
}
