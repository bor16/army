#include "Vampire.h"

Vampire::Vampire(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->action = std::unique_ptr<VampireAction>(new VampireAction());
}

Vampire::~Vampire() {}

void Vampire::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}

void Vampire::counterAttack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}
