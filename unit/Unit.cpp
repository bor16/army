#include "Unit.h"
#include "../unit/Necromancer.h"

Unit::Unit(State* state) : state(state) {}

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
UnitClass Unit::getTitle() const {
    return state->getTitle();
}

void Unit::takeDamage(int damage) {
    this->state->takeDamage(damage);
}
void Unit::takeMagDamage(int damage) {
    this->state->takeMagDamage(damage);
}
void Unit::restoreHp(int points) {
    this->state->restoreHp(points);
}

void Unit::attach(Necromancer* observer) {
    observers->insert(observer);
    observer->attachSubject(this);
}
void Unit::detach(Necromancer* observer) {
    observers->erase(observer);
    observer->detachSubject(this);
}
void Unit::notify() {
    std::set<Necromancer*>::iterator observer;
    
    for ( observer = observers->begin(); observer != observers->end(); ++observer ) {
        (*observer)->update();
        this->detach(*observer);
    }
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getState();
    return out;
}
