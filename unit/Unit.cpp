#include "Unit.h"
#include "Necromancer.h"

Unit::Unit(State* state) : state(state) {}

Unit::~Unit() {
    delete state;
}

const int Unit::getHp() const {
    return this->state->getHp();
}
const int Unit::getMaxHp() const {
    return this->state->getMaxHp();
}
const int Unit::getDamage() const {
    return this->state->getDamage();
}
Class Unit::getTitle() const {
    return this->state->getTitle();
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

void Unit::attack(Unit& target) {
    this->state->ensureIsAlive();
    
    target.takeDamage(this->getDamage());
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    }
}

void Unit::counterAttack(Unit& target) {
    target.takeDamage(this->getDamage()/2);
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
