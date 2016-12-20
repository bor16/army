#include "Necromancer.h"
#include "../modifier/Aid.h"

Necromancer::Necromancer(UnitClass title, int maxHp, int damage, int maxMana) : Wizard(title, maxHp, damage, maxMana) {
    this->action = std::unique_ptr<NecromancerAction>(new NecromancerAction());
    this->subjects = nullptr;
}

Necromancer::~Necromancer() {
    if ( subjects != nullptr ) {
        delete subjects;
    }
}

void Necromancer::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}

void Necromancer::counterAttack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->counterAttack(target, attacker);
}

void Necromancer::update() {
    Aid aid;
    
    aid = 20;
    
    this->takeImpact(aid);
}

void Necromancer::attachSubject(ISubject* subject) {
    subjects->insert(subject);
}

void Necromancer::detachSubject(ISubject* subject) {
    subjects->erase(subject);
}

void Necromancer::notifySubject() {
    std::set<ISubject*>::iterator subject;
    
    for ( subject = subjects->begin(); subject != subjects->end(); ++subject ) {
        (*subject)->detach(this);
    }
}
