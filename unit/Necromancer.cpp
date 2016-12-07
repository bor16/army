#include "Necromancer.h"

Necromancer::Necromancer(Class title, int maxHp, int damage, int maxMana) : Wizard(title, maxHp, damage, maxMana) {}

Necromancer::~Necromancer() {}

void Necromancer::attack(Unit& target) {
    this->state->ensureIsAlive();
    
    target.takeDamage(this->getDamage());
    target.attach(this);
    
    if ( target.getHp() != 0 ) {
        target.counterAttack(*this);
    } else {
        target.notify();
    }
}

void Necromancer::counterAttack(Unit& target) {
    target.takeDamage(this->getDamage()/2);
    target.attach(this);
    if ( target.getHp() == 0 ) {
        target.notify();
    }
}

void Necromancer::update() {
    this->restoreHp(20);
}

void Necromancer::attachSubject(Unit* subject) {
    subjects->insert(subject);
}

void Necromancer::detachSubject(Unit* subject) {
    subjects->erase(subject);
}

void Necromancer::notifySubject() {
    std::set<Unit*>::iterator subject;
    
    for ( subject = subjects->begin(); subject != subjects->end(); ++subject ) {
        (*subject)->detach(this);
    }
}
