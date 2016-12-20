#include "Rogue.h"

Rogue::Rogue(UnitClass title, int maxHp, int damage) : Soldier(title, maxHp, damage) {
    this->action = std::unique_ptr<RogueAction>(new RogueAction());
}

Rogue::~Rogue() {}

void Rogue::attack(Unit& target, Unit& attacker) {
    this->ensureIsAlive();
    this->action->attack(target, attacker);
}
