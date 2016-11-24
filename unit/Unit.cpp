#include "Unit.h"

Unit::Unit(const std::string& name, const std::string& unitClass, int maxHp, int damage) : state(new State(name, unitClass, maxHp, damage)) {}

Unit::~Unit() {
    delete state;
}

const State& Unit::getState() const {
    return *state;
}
const int Unit::getHp() const {
    return state->getHp();
}
const int Unit::getMaxHp() const {
    return state->getMaxHp();
}
const int Unit::getDamage() const {
    return state->getDamage();
}
const std::string& Unit::getName() const {
    return state->getName();
}
const std::string& Unit::getUnitClass() const {
    return state->getUnitClass();
}

void Unit::takeDamage(int damage) {
    this->state->takeDamage(damage);
}
void Unit::restoreHp(int points) {
    this->state->restoreHp(points);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getState();
    return out;
}
