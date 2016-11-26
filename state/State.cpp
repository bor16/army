#include "State.h"

State::State(const std::string& name, const std::string& unitClass, int maxHp, int damage) : name(name), unitClass(unitClass), hp(maxHp), maxHp(maxHp), damage(damage) {}

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
const std::string& State::getName() const {
    return this->name;
}
const std::string& State::getUnitClass() const {
    return this->unitClass;
}

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        // throw DeadUnitException("ERROR: unit is dead");
    }
}

void State::setHp(int hp) {
    this->hp = hp;
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
    out << state.getName() << " the " << state.getUnitClass() << ": ";
    out << "hp(" << state.getHp() << "/" << state.getMaxHp() << "), ";
    out << "damage(" << state.getDamage() << ")";
    return out;
}
