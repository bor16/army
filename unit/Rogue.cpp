#include "Rogue.h"

Rogue::Rogue(unitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->action = new RogueAction();
}

Rogue::~Rogue() {
    delete action;
}

void Rogue::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}
