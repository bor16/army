#include "Unit.h"

Unit::Unit(State* state, Action* action) : state(state), action(action) {}

Unit::~Unit() {
    delete state;
    delete action;
}

void Unit::ensureIsAlive() {
    if ( this->getHealth() == 0 ) {
        throw DeadActionException();
    }
}

UnitClass Unit::getTitle() const {
    return this->state->getTitle();
}
const Health Unit::getHealth() const {
    return this->state->getHealth();
}
const int Unit::getDamage() const {
    return this->state->getDamage();
}
void Unit::takeImpact(Modifier& mod) {
    this->state->takeImpact(mod);
}
void Unit::takeMagDamage(Modifier& mod) {
    this->state->takeMagDamage(mod);
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
