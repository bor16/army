#include "Unit.h"

Unit::Unit(State* state) : state(state), action(new Action()) {}

Unit::~Unit() {
    delete state;
    delete action;
}

void Unit::ensureIsAlive() {
    if ( this->state->getHp() == 0 ) {
        throw DeadActionException();
    }
}

UnitClass Unit::getTitle() const {
    return this->state->getTitle();
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
void Unit::takeDamage(int damage) {
    this->state->takeDamage(damage);
}
void Unit::takeMagDamage(int damage) {
    this->state->takeMagDamage(damage);
}
void Unit::restoreHp(int points) {
    this->state->restoreHp(points);
}

void Unit::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}

void Unit::counterAttack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->counterAttack(target, attacker);
}

void Unit::attach(IObserver* observer) {
    observers->insert(observer);
    observer->attachSubject(this);
}

void Unit::detach(IObserver* observer) {
    observers->erase(observer);
    observer->detachSubject(this);
}

void Unit::notify() {
    std::set<IObserver*>::iterator observer;
    
    for ( observer = observers->begin(); observer != observers->end(); ++observer ) {
        (*observer)->update();
        this->detach(*observer);
    }
}
