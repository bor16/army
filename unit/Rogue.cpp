#include "Rogue.h"

Rogue::Rogue(Class title, int maxHp, int damage) : Soldier(title, maxHp, damage) {}

Rogue::~Rogue() {}

void Rogue::attack(Unit& target) {
    this->state->ensureIsAlive();
    
    target.takeDamage(this->getDamage());
}
