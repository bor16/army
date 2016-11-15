#include "Unit.h"

Unit::Unit(const std::string& name, const std::string& unitClass, int maxHp, int physDmg) : state(new State(maxHp, physDmg)), name(name), unitClass(unitClass) {
    std::cout << "***Unit***" << std::endl;
}

Unit::~Unit() {
    delete state;
    std::cout << "~~~Unit~~~" << std::endl;
}

void Unit::setHp(int physPts, int magPts) {
    int points = this->getHp() + physPts + magPts;
    
    if ( points > this->getMaxHp() ) {
        points = this->getMaxHp();
    }
    if ( points <= 0 ) {
        points = 0;
    }
    
    state->setHp(points);
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
const int Unit::getPhysDmg() const {
    return state->getPhysDmg();
}
const std::string& Unit::getName() const {
    return this->name;
}
const std::string& Unit::getUnitClass() const {
    return this->unitClass;
}

const bool Unit::dead() const {
    return this->getHp() == 0;
}
const bool Unit::werewolf() const {
    return state->werewolf();
}
const bool Unit::vampire() const {
    return state->vampire();
}

void Unit::becomeWerewolf() {
    if (!vampire()) {
        state->becomeWerewolf();
    }
}
void Unit::becomeVampire() {
    if (!werewolf()) {
        state->becomeVampire();
    }
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " the " << unit.getUnitClass() << ": ";
    out << unit.getState();
    
    return out;
}
