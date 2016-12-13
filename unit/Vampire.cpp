#include "Vampire.h"

Vampire::Vampire(unitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->action = new VampireAction();
}

Vampire::~Vampire() {
    delete action;
}

void Vampire::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}

void Vampire::counterAttack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}
